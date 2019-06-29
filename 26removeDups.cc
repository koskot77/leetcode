class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        if( nums.size() == 0 ) return 0;
        for(int i=1, last=nums[0]; i<nums.size() - cnt; ){
            if( nums[i] == last ){
                ++cnt;                
                for(int j=i-1; j<nums.size()-cnt; ++j)
                    nums[j] = nums[j+1];
                last = nums[i-1];
                continue;
            }
            last = nums[i];
            ++i;
        }
        return nums.size() - cnt;
    }
};
