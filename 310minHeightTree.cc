#include<set>
#include<map>
#include<list>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int bfsLongestPath(int s, map<int,list<int>>& graph){

        set<int> explored;
        queue<int> fifo;
        map<int,int> pathTo;

        fifo.push(s);
        explored.insert(s);
        pathTo[s] = 0;
        int maxPath = 0;

        // standard bfs:
        while( !fifo.empty() ){
            int cur = fifo.front();
            fifo.pop();
            for(auto e : graph[cur]){
                if( explored.find(e) != explored.end() ) continue;
                pathTo[e] = pathTo[cur] + 1;
                if( maxPath < pathTo[e] ) maxPath = pathTo[e];
                fifo.push(e);
                explored.insert(e);
            }
        }

        return maxPath;
    }



    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if( n==0 ) return vector<int>();
        if( n==1 ){ vector<int> retval; retval.push_back(0); return retval; }
/*
        // the quadratic time solution is simple:

        // make a quick look-up for the edges connected to every node
        map<int,list<int>> graph;
        for(auto edge : edges){
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        map<int,int> node2height;
        int minHeight = 1000000;

        for(int node=0; node<n; node++){
            node2height[node] = bfsLongestPath(node,graph);
            if( minHeight > node2height[node] )
                minHeight = node2height[node];
        }

        vector<int> retval;
        for(auto n: node2height)
            if( n.second == minHeight ) retval.push_back(n.first);

        return retval;
*/

        // the following linear time solution is inspired by the https://discuss.leetcode.com/topic/30572/share-some-thoughts/2 post
        map<int,set<int>> adj;
        for(auto edge : edges){
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }

        vector<int> leaves;
        for(auto node : adj)
            if( node.second.size()==1 ) leaves.push_back(node.first);

        while( n>2 ){
            n -= leaves.size();
            vector<int> newLeaves;
            for(auto l1 : leaves){
                int l2 = *(adj[l1].begin());
                adj[l2].erase(l1);
                if( adj[l2].size() == 1 ) newLeaves.push_back(l2);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

int main(void){
    Solution s;

    vector<pair<int, int>> edges;

    int n=4;
    edges.push_back( make_pair(1,0) );
    edges.push_back( make_pair(1,2) );
    edges.push_back( make_pair(1,3) );

    for(auto res : s.findMinHeightTrees(n,edges) )
        cout<<" "<<res<<endl;

    return 0;
}
