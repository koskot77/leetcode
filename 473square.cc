// err #0: not mine
//  4^N was the right thinking, but I've overcoplicated it with NchooseM
class Solution {
public:
    bool dfs(vector<int>&nums, vector<int>& sides, int index, int trg){
        if( index == nums.size() ){
            if( sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3] )
                return true;
            else
                return false;
        }
        for(int side = 0; side<4; ++side){
            if( sides[side] + nums[index] > trg )
                continue;
            sides[side] += nums[index];
            if( dfs(nums, sides, index+1, trg) )
                return true;
            sides[side] -= nums[index];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        // check if you can make square
        int sum = accumulate(nums.begin(),nums.end(),0);
        if( sum == 0 ) return false;
        if( sum % 4 ) return false;
        vector<int> sides(4);
        return dfs(nums, sides, 0, sum/4);
    }
};
