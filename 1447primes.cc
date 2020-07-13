// https://leetcode.com/problems/simplified-fractions/
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        const int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
        if( n == 1 || n == 0 ) return vector<string>();
        // answer = simplifiedFractions(n-1) + [1:n-1]/n
        // this last loop [1:n-1]/n should be simplified
        vector<string> retval = simplifiedFractions(n-1);
        // discard i if n and i has any common dividers
        for(int i=1; i<n; ++i){
            int j = 0;
            while( j<15 )
                if( (n%primes[j])==0 && (i%primes[j])==0 ){
                    break;
                } else ++j;
            if( j == 15 ) retval.push_back(to_string(i)+"/"+to_string(n));
        }
        return retval;
    }
};

