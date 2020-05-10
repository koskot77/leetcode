// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer
class Solution {
public:
    int maxDiff(int num) {

        // firstly, break num into digits and identify the order of most significant one
        int digits[9] = {}, highest = 0;
        for(int p=0, order=1; p<9; ++p){
            digits[p] = (num/order) % 10;
            order *= 10;
            if( digits[p]>0 ) highest = p;
        }

        // replacing the most significant digit for 9 and for 1 should give maximum and minimum numbers
        // ... unless they are already 9 or 1 in which case we go to the next significant digit (and on...)

        // define results of applying the algorithm
        int maximum = 0, minimum = 0

        // define digits that are going to be replaced
        int to_replace_max = digits[highest], to_replace_min = digits[highest];

        //  and find these digits running down until they are not 9 and 1 (or 0!)
        for(int p=highest; p>0 && digits[p]==9; --p) to_replace_max = digits[p-1];
        for(int p=highest; p>0 && digits[p]<=1; --p) to_replace_min = digits[p-1];

        // remember if this will be not the most significant digit we replace (in which case we can replace for 0)
        bool leading_1 = digits[highest] == 1;

        // and finally, replace
        for(int p=0, order=1; p<=highest; ++p){
            maximum += (digits[p] != to_replace_max ? digits[p] : 9) * order; // yes, it may replace 9 for 9, ... big deal
            minimum += (digits[p] != to_replace_min ? digits[p] : (leading_1&&to_replace_min!=1?0:1)) * order; // maybe this ternary is a bit too much ...
            order   *= 10;
        }

        // not much left to do
        return maximum - minimum;
    }
};
