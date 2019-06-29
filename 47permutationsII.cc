// partially not mine:
class Solution {
public:
    void helper(vector<int>& n, set<vector<int>>& r, vector<int>& p, vector<bool>& u){
        if( p.size() == n.size() ){
            r.insert(p);
            return;
        }
        for(int i=0; i<n.size(); ++i){
            if( !u[i] ){
                u[i] = true;
                p.push_back(n[i]);
                helper(n,r,p,u);
                p.pop_back();
                u[i] = false;
            }
        }        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> retval;
        vector<int> partial;
        vector<bool> used(nums.size(),false);
        helper(nums,retval,partial,used);
        vector<vector<int>> retval2;
        copy(retval.begin(), retval.end(), back_inserter(retval2));
        return retval2;
    }
};
