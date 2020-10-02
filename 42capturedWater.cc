// divide and conquer:
//  1) scan for the first higest point except for a specified position (undef first time)
//  2) partition to the left and right with pos in vector specifying partition pos
//  3) 
// too complicated, follow a linear algorithm from one of the dicussions:
// 1) run from both ends to the middle
// 2) choose lower from the two sides as the level cannot be higher than that
// 3) add to the result the depth from the current maximum, or update the maximum
class Solution {
public:
    int trap(vector<int>& height) {
        if( height.empty() ) return 0;
        int left = 0, right = height.size()-1, retval = 0;
        int maxLeft = height[left], maxRight = height[right];
        while( left < right ){
            if( height[left] < height[right] ){
                if( height[left] < maxLeft ){
                    retval += maxLeft - height[left];
                } else
                    maxLeft = height[left];
                ++left;
            } else {
                if( height[right] < maxRight ){
                    retval += maxRight - height[right];
                } else
                    maxRight = height[right];
                --right;
            }
        }
        return retval;
    }
};
