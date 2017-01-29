// https://leetcode.com/contest/leetcode-weekly-contest-13/problems/total-hamming-distance/
// https://discuss.leetcode.com/category/609/total-hamming-distance

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // Every number that has 1 in a certain bit will contribute to
        //  increment of hamming distance when "paired" with every other number
        //  that has 0 in this bit. So look at every single bit exclusively,
        //  check how many numbers has it set to 1 and how many has 0,
        //  take a product and sum it over all 32 bits.
        int retval = 0;
        for(int bit=0; bit<32; bit++){
            int nOnes = 0, nZeros = 0;
            for(int i=0; i<nums.size(); i++)
                if( nums[i] & (1<<bit) ) nOnes++;
                else nZeros++;
                retval += nZeros * nOnes;
        }
/*
        int retval = 0;
        for(int i=0; i<nums.size(); i++)
            for(int j=0; j<nums.size(); j++)
                if( i<j ){
                    int sum = 0;
                    int xr = nums[i]^nums[j];
                    for(int bit=0; bit<32; bit++)
                        if( xr & (1<<bit) ) sum++;
                    retval += sum;
                }
*/         return retval;

    }

};

