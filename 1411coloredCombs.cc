class Solution {
public:
    int numOfWays(int n) {
        // there are two categories of rows 2-colored and 3-colored
        // using examples from the test case n=1 one can check that such rows can be continued as follows:
        //   2-colored -> 3 * 2-colored + 2 * 3-colored (total 5 ways to continue)
        //   3-colored -> 2 * 2-colored + 2 * 3-colored (total 4 ways to continue)
        // (notice: whould each category be continued by the same number of ways, the answer is a power law)
        // at the first level (n=1) we have 6 2-colored and 6 3-colored rows:
        pair<unsigned long long, unsigned long long> level{6ULL, 6LL}; 
        // continue n rows down
        for(int i=1; i<n; ++i){
            // calculate now many 2-colored and 3-colored continuations are at the next level
            unsigned long long n_2c_next = level.first*3 + level.second*2;
            unsigned long long n_3c_next = level.first*2 + level.second*2;
            // rember the next level results and avoid overflow with '%'
            level.first  = n_2c_next % 1000000007;
            level.second = n_3c_next % 1000000007;
        }
        // just make sure the sum is not overflowing either
        return (level.first + level.second) % 1000000007;
    }
};
