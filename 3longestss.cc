#include<map>
#include<iostream>
using namespace std;

// Just one trick here: keep updating the map with new symbols as we slide down the string,
//   but ignore matches that are found before your current substring candidate starts:
// https://discuss.leetcode.com/topic/52631/c-solution-with-std-map

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> dict;
        int subStart  = 0;
        int maxSubLen = 0;

        for(int pos=0; pos<s.length(); pos++){
            /* the character repeats and it was encountered in the current substring candidate? */
            if( dict.find( s[pos] ) != dict.end() && dict[ s[pos] ] >= subStart )
                subStart = dict[ s[pos] ] + 1;
            dict[ s[pos] ] = pos;
            if( pos+1 - subStart > maxSubLen ) maxSubLen = pos+1 - subStart;
        }

        return maxSubLen;
    }
};

int main(void){
    Solution s;
    cout<<s.lengthOfLongestSubstring(string("jxdlnaaij"))<<endl;
    return 0;
}
