class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0, len = nums.size();
        for(int i=0; i<nums.size()-cnt;){
            if( nums[i] == val ){
                for(int j=i; j<nums.size()-1; ++j) // err #1: ?
                    nums[j] = nums[j+1];
                ++cnt;
                continue;
            }
            ++i; // err #2: consequent dups
        }
        return len - cnt;
    }
};
