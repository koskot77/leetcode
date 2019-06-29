class Solution {
public:
    void backtrack(vector<int>& cand, set<vector<int>>&ret, vector<int>& part, int trg, int pos){
        if( trg == 0 ){   // err #0: either
            ret.insert(part);
            return;
        }
        if( pos == cand.size() || trg-cand[pos] < 0 ) return; // err #1: check end

        part.push_back(cand[pos]);
        backtrack(cand,ret,part,trg-cand[pos],pos+1); // err #0: or

        part.pop_back();
        backtrack(cand,ret,part,trg,pos+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> retval;
        vector<int> partial;
        backtrack(candidates,retval,partial,target,0);
        vector<vector<int>> retval2;
        copy(retval.begin(),retval.end(),back_inserter(retval2));
        return retval2;
    }
};
