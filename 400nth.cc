/// https://discuss.leetcode.com/topic/60401/annotated-c-solution
#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digits[] = {0,1,2,3,4,5,6,7,8,9};
        // trivial case first
        if( n < 10 ){
            return digits[n];
        }
        // our sequence is just a series of non-delimited numbers 
        // position _n_ in this sequence points to a certain digit of some number
        // these are 9 one-digit numbers in the trivial case (call it _order_=0)
        //  then they turn to 90 two-digit numbers ranging in [10-99] (call it _order_=1)
        //  after that they turn to 900 three-digit numbers from [100-999] range (_order_=2)
        // let us first identify which _order_ we deal with for the given _n_ and
        //  subtract from _n_ the lengths of each of the previous orders
        int order = 1;
        for( ; ; order++){
            unsigned long long shift = (pow(10,order) - pow(10,order-1))*order;
            if( n <= shift ) break;
            n -= shift;
        }
        // now _n_ is pointing to a digit in a sequence of same width numbers
        // let us identify the number (keep in mind that _n_ start counting from 1)
        int num = (n-1) / order + pow(10,order-1) ;
        //  and the position in this number
        int pos = order-1 - (n-1) % order;
        // so we identified the number we are on and digit's position in this number
        while( pos-- ) num /= 10;
        // return it
        return digits[num%10];
    }
};

int main(void){
    Solution s;

    cout<<" "<<s.findNthDigit(1000000000)<<endl;

//    for(int i=1; i<100; i++) cout<<i;
//    cout<<endl;

    return 0;
}
