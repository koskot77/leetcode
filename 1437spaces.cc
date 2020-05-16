// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/submissions/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool retval = true;
        for(int pos=0, cnt=1000000; pos < nums.size(); ++pos, ++cnt){ // error #2: edge case of starting with 0!
            if(nums[pos] == 1 && cnt !=0){
                retval &= cnt > k; // error #1: think, don't try
                cnt = 0;
                if( retval == false ) return false;
            }
        }
        return retval;
    }
};
