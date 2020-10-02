// brutforce: check recursively (target-candidate), backtrack
class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>> &result, vector<int> &current, int pos, int target) {
        if( target <  0 ) return;
        if( target == 0 ){ result.push_back(current); return; }
        for(int i=pos; i<candidates.size(); ++i){
            current.push_back(candidates[i]);
            dfs(candidates, result, current, i, target-candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates,res,cur,0,target);
        return res;
    }
};
