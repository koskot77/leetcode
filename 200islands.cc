class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& explored){
        if( x<0 || x>=grid[0].size() || y<0 || y>=grid.size() || explored[y][x] || grid[y][x] == '0' ) return; // err #1: forgot to check "land"
        explored[y][x] = true;
        dfs(x-1,y,grid,explored);
        dfs(x+1,y,grid,explored);
        dfs(x,y-1,grid,explored);
        dfs(x,y+1,grid,explored);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        vector<vector<bool>> explored(grid.size());
        for(int y=0; y<grid.size(); ++y)
            explored[y].resize(grid[y].size()); // err #2: forgot to index explored

        for(int y=0; y<grid.size(); ++y)
            for(int x=0; x<grid[0].size(); ++x){
                if( grid[y][x] == '0' ) continue; // warn #1: optimization
                if( !explored[y][x] ) ++count;
                dfs(x,y,grid,explored);
            }
        return count;
    }
};
