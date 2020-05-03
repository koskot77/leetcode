// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer
class Solution {
public:
    int maxDiff(int num) {
        int digits[9] = {}, highest = 0;
        for(int p=0, order=1; p<9; ++p){
            digits[p] = (num/order) % 10;
            order *= 10;
            if( digits[p]>0 ) highest = p;
        }
        int maximum = 0, minimum = 0, to_replace_max = digits[highest], to_replace_min = digits[highest];
        bool leading_1 = digits[highest] == 1;
        for(int p=highest; p>0 && digits[p]==9; --p) to_replace_max = digits[p-1];
        for(int p=highest; p>0 && digits[p]<=1; --p) to_replace_min = digits[p-1]; // error #2: test case 1101057 -> '<=1'
        for(int p=0, order=1; p<=highest; ++p){
            maximum += (digits[p] != to_replace_max ? digits[p] : 9) * order;
            minimum += (digits[p] != to_replace_min ? digits[p] : (leading_1&&to_replace_min!=1?0:1)) * order; // error #1: obvious leading_1&&to_replace_min!=1 (all ones)!
            order   *= 10;
        }
        return maximum - minimum;
    }
};
