// strings not numbers: factorial-like answer: [10], [10*9], [10*9*8], ...
// numbers:
// n=1: 0,1,2,3,4,5,6,7,8,9 = 10
// n=2: (n=1)*one_less_choises: [0(!)+ 0*(1,2,3,4,5,6,7,8,9)]+ 1*(0,2,3,4,5,6,7,8,9)+ 2*(0,1,3,4,5,6,7,8,9), ... = (n=1)+9x9
// n=3: (n=2)*two_less_choises: [0(!)+ 0*(1,2,3,4,5,6,7,8,9) + 01*(2,3,4,5,6,7,8,9) + ...] + 10*(2,3,4,5,6,7,8,9) + ... =(n=2) + 9x9x8
// 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        int before = countNumbersWithUniqueDigits(--n);
        int retval = 9;
        for(int i=9; n>0 && i>0; --n, --i) retval *= i;
        return before + retval;
    }
};
