// fails ...
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unsigned long long dp[ obstacleGrid.size() ][ obstacleGrid[0].size() ];
        bzero(dp, sizeof(dp));
        for(int row=0; row<obstacleGrid.size() && obstacleGrid[row][0] == 0; ++row) dp[row][0] = 1;
        for(int col=0; col<obstacleGrid[0].size() && obstacleGrid[0][col] == 0; ++col) dp[0][col] = 1;
        for(int col=1; col<obstacleGrid[0].size(); ++col){
            for(int row=1; row<obstacleGrid.size(); ++row){
                if( obstacleGrid[row-1][col] == 0 && obstacleGrid[row][col-1] == 0 )
                    dp[row][col] = dp[row][col-1] + dp[row-1][col];
                else if( obstacleGrid[row-1][col] != 0 )
                    dp[row][col] = dp[row][col-1];
                else if( obstacleGrid[row][col-1] != 0 )
                    dp[row][col] = dp[row-1][col];
                else dp[row][col] = 0;
            }
        }
        return dp[ obstacleGrid.size()-1 ][ obstacleGrid[0].size()-1 ];
    }
};
