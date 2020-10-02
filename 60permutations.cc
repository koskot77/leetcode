// the idea is to swap the elements in a certain order while counting it in k (runtime is O(n!))
// the order: swap from the end:
// 1 234
// 1 243
// 1 324
// 1 342
// 1 423
// 1 432
// i.e. number of swaps with the first element fixed = (n-1)! (as with the first two fixed it is (n-2)!)
// the next series with the first element fixed will be starting with 2 and other (n-1)! swaps for the rest (e.g. 2 134)
// the general scheme:
//   1) determine the first number as (k-1)/(n-1)! (the subseries index)
//   2) position in the subseries with n-1 elemets, the new k, is given with (k-1)%(n-1)! and the subseries is with 
class Solution {
public:
    void helper(list<char> &numbers, int n, int k, string &retval){
        if( n == 0 ) return;
        int fac = 1;
        for(int tmp=2; tmp<n; ++tmp) fac *= tmp;
        int index = (k-1)/fac; // (k-1)/(n-1)!;
        list<char>::iterator it = numbers.begin();
        for(int i=0; i<index && it!=numbers.end(); ++it, ++i);
        retval += *it;
        numbers.erase(it);
        helper(numbers, n-1, (k-1)%fac+1, retval);
    }
    string getPermutation(int n, int k) {
        list<char> numbers{'1','2','3','4','5','6','7','8','9'};
        string retval;
        helper(numbers,n,k,retval);
        return retval;
    }
};
