class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // strategy: (1) sort, (2) run N times N*N nested loops
        sort(nums.begin(), nums.end());
        set<vector<int>> retval;
        for(int l=0; l<nums.size(); ++l){
            for(int k=l+1; k<nums.size(); ++k){
                int start = k+1;
                int finish = nums.size()-1;
                while( start < finish ){
                    int abcd = nums[l] + nums[k] + nums[start] + nums[finish];
                    if( abcd < target ) ++start;
                    if( abcd > target ) --finish;
                    if( abcd == target ){
                        retval.insert(vector<int>({nums[l],nums[k],nums[start],nums[finish]}));
                    ++start;
                    --finish;
                    }
                }
            }
        }
        vector<vector<int>> retval2;
        copy(retval.begin(),retval.end(),back_inserter(retval2));
        return retval2;
    }
};
