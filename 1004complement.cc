class Solution {
public:
    int bitwiseComplement(int N) {
        if( N == 0 ) return 1;
        int n_bits = 1, M = N;
        while( M /= 2 ) ++n_bits;
        return N ^ ((1<<n_bits) - 1);
    }
};
