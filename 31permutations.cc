// err #0: general logic: took too long to realize that the end is more important
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1) run a pointer from behind and look for the first "drop"
        // 2) everything to the left will stay untouched
        // 3) dropping digit has to be swapped with a bigger digit on the right
        // 4) the rest has to be sorted
        // examples:
        // 1,2,3,4 -> 1,2,4,3
        // 1,2,4,3 -> 1,3,4,2 -> 1,3,2,4
        int i = nums.size()-2;
        for(; i>=0; --i){
            if( nums[i] < nums[i+1] ){
                int cand = nums.size()-1;
                while( nums[cand]<=nums[i] ) --cand;
                swap(nums[i],nums[cand]);
                sort(nums.begin()+i+1,nums.end()); // err #1: forgot to "reset" the rest
                break;
            }
        }
        if(i < 0) reverse(nums.begin(),nums.end());
    }
};
