class Solution {
public:
    int search(vector<int>& nums, int target) {
        // a variation of a binary search
        int lower = 0;
        int upper = nums.size()-1;
        if( nums.size() == 1 ) return (nums[0]==target?0:-1);
        if( nums.size() == 0 ) return -1;
        // whenever lower < upper the array is sorted
        while( lower < upper ){
            int mid = (lower + upper) / 2;
            if( nums[mid] == target ) return mid;

            if( nums[lower] <= nums[mid] ){ // err #2: ==
                if( target >= nums[lower] && target < nums[mid] ) // err #3: ==
                    upper = mid;
                else
                    lower = mid+1;
            } else {
                if( target > nums[mid] && target <= nums[upper] )
                    lower = mid+1;
                else
                    upper = mid;
            }
        }
        return nums[lower] == target ? lower : -1; // err #1: ==
    }
};
