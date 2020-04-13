#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

// my brut-force solution:
class Solution {
public:
    const unordered_set<string>& helper(int a, int b, int c, unordered_map<int,unordered_set<string>> &cache){
        int key = a + b*1000 + c*1000000;

        unordered_map<int,unordered_set<string>>::const_iterator match = cache.find(key);
        if( match != cache.end() ){
            return match->second;
        }

        if( a==0 && b==0 && c==0 ){
            return cache[key];
        }

        if(a>0){
          for(const auto &str : helper(a-1, b, c, cache)){
            for(int pos=0; pos<str.length()+1; ++pos){
                string s = str.substr(0,pos) + "a" + str.substr(pos);
                if( s.find("aaa") == string::npos ){
                    cache[key].insert(s);
                }
            }
          }
        }

        if(b>0){
          for(const auto &str : helper(a, b-1, c, cache)){
            for(int pos=0; pos<str.length()+1; ++pos){
                string s = str.substr(0,pos) + "b" + str.substr(pos);
                if( s.find("bbb") == string::npos ){
                    cache[key].insert(s);
                }
            }
          }
        }

        if(c>0){
          for(const auto &str : helper(a, b, c-1, cache)){
            for(string::size_type pos=0; pos<str.length()+1; ++pos){
                string s = str.substr(0,pos) + "c" + str.substr(pos);
                if( s.find("ccc") == string::npos ){
                    cache[key].insert(s);
                }
            }
          }
        }
        return cache[key];
    }

    string longestDiverseString(int a, int b, int c) {
        unordered_map<int,unordered_set<string>> cache;
        cache.insert(make_pair(0,unordered_set<string>{""}));
        int progress = 0;
        unordered_set<string> results = helper(a,b,c,cache);
        string best;
        for(const auto &hit : cache){
            for(const auto &str : hit.second){
                if( str.length() > best.length() )
                    best = str;
            }
        }
        return best;
    }
};

// Thinking of composing a string based on fewquency of letters I came acros an elegant solution with the priority_queue:
// https://leetcode.com/problems/longest-happy-string/discuss/574645/Easy-understood-PriorityQueue-Solution-in-C%2B%2B :

#include <utility>
#include <queue>

class Solution2 {
public:

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if( a>0 ) pq.push(make_pair(a,'a'));
        if( b>0 ) pq.push(make_pair(b,'b'));
        if( c>0 ) pq.push(make_pair(c,'c'));

        string retval;

        for(char prev1='#', prev2='#'; !pq.empty(); ){
            pair<int,char> p1 = pq.top(); pq.pop();
            int cnt = p1.first; char letter = p1.second;
            if( letter == prev1 && letter == prev2 ){
                if( pq.empty() ) return retval;
                pair<int,char> p2 = pq.top(); pq.pop();
                int _cnt = p2.first; char _letter = p2.second;
                prev2 = prev1;
                prev1 = _letter;
                retval += _letter;
                if( --_cnt>0 ) pq.push(make_pair(_cnt,_letter));
                pq.push(make_pair(cnt,letter));
            } else {
                prev2 = prev1;
                prev1 = letter;
                retval += letter;
                if( --cnt>0 ) pq.push(make_pair(cnt,letter));
            }
        }

        return retval;
    }
};

int main(void){
    Solution2 s;
    std::cout<< s.longestDiverseString(10,10,1) << std::endl;
    return 0;
}
