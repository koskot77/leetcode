// https://leetcode.com/problems/minimum-genetic-mutation/
// https://discuss.leetcode.com/topic/67240/c-bfs-hashed-look-ups-o-size-bank-running-time
#include<set>
#include<map>
#include<list>
#include<array>
#include<queue>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Convert the bank into a graph and run BFS to get a shortest path
    int minMutation(string start, string end, vector<string>& bank) {
        // check for the trivial case
        if( start == end ) return 0;

        // assign integer labels to the strings in the bank
        map<string,int> hash;
        hash[start] = 0; // note, start is not in the bank, add it there
        int index = 1;
        for_each( bank.begin(), bank.end(), [&hash,&index](string &s) { hash[s] = index++; } );

        // initialize the graph with verticies/labels and empty lists
        map<int,list<int>> graph; 
        for(int i=0; i<index; i++)
            graph.insert( make_pair(i,list<int>()) );

        // associate vertex (labeled string) with all other vertices that are different by exactly one symbol
        map<char,array<char,3>> replacement = {{'A',{'C','T','G'}},{'C',{'A','T','G'}},{'T',{'C','A','G'}},{'G',{'C','T','A'}}};
        for_each( graph.begin(),
                  graph.end(),
                  [&hash,&bank,&replacement,&start] (pair<const int,list<int>> &v) {
                        string gene = ( v.first == 0 ? start : bank[v.first-1] );
                        // try replacing every single symbol in the string
                        for(int pos=0; pos<gene.length(); pos++)
                            // run over all the replacement variants
                            for(auto symbol : replacement[ gene[pos] ]){
                                string newGene = gene;
                                newGene[pos] = symbol;
                                // look for the match in the bank
                                auto match = hash.find(newGene);
                                if( match != hash.end() )
                                    v.second.push_back( match->second );
                           }

                  }
        );
        for(auto v : graph){
            cout << " " << v.first << endl;
            for(auto t : v.second)
                cout << " -> " << t <<endl;
        }


        // canonical BFS:
        int retval = -1;
        map<int,int> path;
        queue<int> fifo;
        fifo.push(0);
        set<int> explored;
        while( !fifo.empty() && retval<0 ){
            int node = fifo.front();
            fifo.pop();
            explored.insert(node);
            for(auto n : graph[node])
                if( explored.find(n) == explored.end() ){
                    explored.insert(n);
                    fifo.push(n);
                    path[n] = path[node] + 1;
                    if( bank[n-1] == end ){
                        retval = path[node] + 1;
                        break;
                    } 
                }
        }
        return retval;
    }
};

int main(void){
    Solution s;
//    vector<string> bank({"AAAACCCC", "AAACCCCC", "AACCCCCC"});
//    cout << s.minMutation("AAAAACCC","AACCCCCC",bank) << endl;
    vector<string> bank({"AACCGGTA"});
    cout << s.minMutation("AACCGGTT","AACCGGTA",bank) << endl;
//        transform( bank.begin(), bank.end(), edges.begin(), [](string &s) -> pair<int, list<int> > { return pair<int, list<int> >(0,list<int>()); } );
/*
start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1

Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2

Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
*/

    return 0;
}

/*
        for(auto gene : bank){
            for(int pos=0; pos<gene.length(); pos++){
                char alphabet[4] = {'A','C','T','G'};
                for(int i=0; i<4; i++){
                    if( alphabet[i] != gene[pos] ){
                        string newGene = gene;
                        newGene[pos] = alphabet[i];
                        if( hash.find(newGene) != hash.end() ){
                            edges[ hash[gene] ] = hash[newGene];
                        }
                    }
                }

            }
        }


*/

