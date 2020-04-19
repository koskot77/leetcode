class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // if this is a tree -> there exists one and only one path to every node
        deque<int> fifo;
        unordered_map<int,set<int>> indexed_edges;
        for(const auto &e : edges){
            if( e[0] < e[1] )
                indexed_edges[e[0]].insert(e[1]);
            else
                indexed_edges[e[1]].insert(e[0]);
        }
        fifo.push_back(1);
        unordered_map<int,size_t> explored{{1,0}}; // node and breadth it was found at
        unordered_map<int,double> probability{{1,1}}; // product of inverse # of edges on the way to the node # warning #2: didn't see the obvious
        while( !fifo.empty() ){
            int v1 = fifo.front();
            fifo.pop_front(); // error #1: used pop_back and not pop_front
            size_t breadth = explored[v1];
            if( breadth>t ) break;
            for(auto v2 : indexed_edges[v1]){
                auto e = explored.find(v2);
                if( e != explored.end() ) continue;
                explored.insert(make_pair(v2,breadth+1));
                fifo.push_back(v2);
                probability[v2] = probability[v1]/indexed_edges[v1].size();
            }
        }
        auto trg = probability.find(target);
        if( trg != probability.end() &&
           (explored[trg->first]==t || (explored[trg->first]<t && indexed_edges[trg->first].empty())) ) // warning #1 didn't thought trough well
            return trg->second;

        return 0;
    }
};
