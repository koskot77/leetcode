//https://leetcode.com/problems/destination-city/submissions/
// error: prefer simpler solutions; no bfs, dfs; unordered_set not unordered_map
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sources;
        for(const auto &e : paths){
            if( !sources.insert(e[0]).second ) cerr << "Assumption doesn't hold" << endl;
        }
        string retval;
        for(const auto &e : paths){
            if( sources.find(e[1]) == sources.end() ){
                retval = e[1];
                break;
            }
        }
        return retval;
    }
};
