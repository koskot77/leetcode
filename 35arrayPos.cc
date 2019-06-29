class Solution {
public:
/*    int binary(vector<int>& nums, int target, int start, int end)
    {
        // terminating condition start == end
        if( start == end ) return start;
        if( end - start == 1 )
        {
            if( nums[start] == target ) return start;
            if( nums[end]   == target ) return end;
            return end;
        }
        int mid = (start + end)/2;
        if( nums[mid] == target )
        {
            return mid;            
        }
        if( nums[mid] > target )
            return binary(nums,target, start, mid);
        return binary(nums,target, mid, end);
    }
    // are nums guaranteed to be unique?
    int searchInsert(vector<int>& nums, int target) {
        if( nums.empty() ) return 0;
        if( target <= nums[0] ) return 0;
        if( target > nums.back() ) return nums.size();
        return binary(nums,target,0,nums.size()-1);
    }
*/
    int searchInsert(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size()-1;
        if( target < nums[0] ) return 0;   // err #2:
        if( target > nums[nums.size()-1] ) //  infinite loop below
            return nums.size();
        while( lower < upper ){
            int mid = (upper + lower) / 2;
            if( nums[mid] == target ) return mid;
            if( target >= nums[lower] && target < nums[mid] )
                upper = mid;
            else
                lower = mid;
            if( lower+1 == upper && target > nums[lower] && target <= nums[upper] )  // err #1: infinite loop
                return upper;
        }
        return lower; // warn: not needed
    }
};
