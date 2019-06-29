class Solution {
public:
    int NchooseM(int N, int M){
        if( M > N/2 ) M = N-M;
        unsigned long long res = 1;
        for(int i=0; i<M; ++i){
            res *= N--;
            res /= (i+1);
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        // number of steps to make: (n-1) + (m-1)
        // at each step you choose 1 to move left or 0 to move down
        // in total you choose n-1 times in this N = n-1 + m-1 steps 
        // NchooseK: N!/(N-K)!/K!
        return NchooseM(n-1 + m-1, n-1);
    }
};
