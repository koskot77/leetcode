class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == target){
                if( first < 0 ){
                    first = i;
                    last  = i;
                } else last = i;
            }
        }
        return vector<int>{first,last};
    }
};
