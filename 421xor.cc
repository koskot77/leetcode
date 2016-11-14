// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// https://discuss.leetcode.com/topic/67825/annotated-c-solution-with-bit-shifts
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // Let's first create a look up for patterns of most significant
        //  bits (MSB) for each of the 32 possible bit shifts
        set<int> lookUp[32];
        for(int shift=0; shift<32; shift++)
            for(auto a : nums)
                lookUp[shift].insert(a>>shift); // just acknowledge any existing

        // Remembering that _a_ xor _b_ = _c_ <=> _a_ xor _c_ = _b_ turns
        //  our search for _b_ achieving the largest _c_ into a construction
        //  of largest _c_ guided by the requirement that corresponding _b_
        //  exists in _nums_.
        // Here our _lookUp_ comes handy as it allows us to home in to the
        //  largest _c_ in a single run over its bits.
        //  To do so we maintain the _cMSB_ - a set of most significant bits
        //  of _c_ that, xor'ed with _a_, match any pattern in _lookUp_
        //  (i.e. match MSB of some _b_). Extending _cMSB_ to include next
        //  bit is simply a single left-bit-shift followed by an optimistic
        //  attempt to search a wider pattern with LSB set to 1 (to maximize
        //  _c_) that, if fails, means that we need to leave it set to 0. 
        int retval = 0;
        for(auto a : nums){
            int cMSB = 0;
            for(int shift=31; shift>=0; shift--){
                cMSB <<= 1;
                auto match = lookUp[shift].find( (a>>shift)^(cMSB|0x1) );
                if( match != lookUp[shift].end() )
                    cMSB |= 1;
            }
            if( retval < cMSB ) retval = cMSB;
        }
        return retval;
    }

    int bruteForce(vector<int>& nums) {
        int maxElem = 0;
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++)
                if( maxElem < (nums[i]^nums[j]) ) maxElem = nums[i]^nums[j];
        return maxElem;
    }

};

int main(void){
    Solution s;
    vector<int> a = {3, 10, 5, 25, 23, 8, 5, 1, 34, 7, 57};
    cout<< s.findMaximumXOR(a) << endl;
    cout<< s.bruteForce(a) << endl;
    return 0;
}
/*
int highestBit = 30;
int a = (1<<13) + (1<<5)
for(; highestBit>=0 && (a&(1<<highestBit)) == 0; highestBit--);
printf("%d\n",highestBit)
printf("%b\n",a)
int complement = a^((1<<highestBit+1)-1);
printf("%b\n",complement)
(commutative,transitive) 
*/
