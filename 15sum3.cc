// err #0: this problem is about avoiding duplicates rather than finding the solutions
// orig, wrong:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // find: a + b == -c
        // maybe quadratic time to get all a+b and dictionary to check if it is -c?
        unordered_multimap<int,pair<int,int>> qwe;
        for(int i = 0; i < nums.size(); ++i)
            for(int j = i+1; j < nums.size(); ++j)
                qwe.insert( make_pair(nums[i]+nums[j], make_pair(i,j)) );

        set<vector<int>> retval;
        for(auto k = 0; k < nums.size(); ++k){
            size_t idx = qwe.bucket(-nums[k]);
            for(auto cand = qwe.begin(idx); cand != qwe.end(idx); ++cand){
                if( k == cand->second.first || k == cand->second.second || cand->first != -nums[k] ) continue;
                vector<int> tmp(3);
                tmp[0] = nums[cand->second.first];
                tmp[1] = nums[cand->second.second];
                tmp[2] = nums[k];
                sort(tmp.begin(),tmp.end());
                retval.insert( tmp );
            }
        }
        vector<vector<int>> retval2;
        copy(retval.begin(), retval.end(), back_inserter(retval2));
        return retval2;
    }
};

// err #1: not mine
// sort and move only forward, two pointers also come handy
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // find: a + b == -c
        // maybe quadratic time to get all a+b and dictionary to check if it is -c?
        set<vector<int>> retval;
        sort(nums.begin(),nums.end());
        for(int k = 0; k<nums.size(); ++k){ // err #2: trivial cases
            int start  = k+1;
            int finish = nums.size()-1;
            while( start < finish ){
                int abc = nums[k] + nums[start] + nums[finish];
                if( abc > 0 ) --finish;
                if( abc < 0 ) ++start;
                if( abc == 0){
                    retval.insert(vector<int>({nums[k], nums[start], nums[finish]}));
                    --finish;
                    ++start;
                }
            }
            
        }
        vector<vector<int>> retval2;
        copy(retval.begin(), retval.end(), back_inserter(retval2));
        return retval2;
    }
};
