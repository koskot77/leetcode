// quadratic time solution is simple:
//   iterate from first to closest reacheable
//   mark all reacheable positions ahead with true
// another solution is to find a path from last node to the first node (DFS) but graph may still have N^2 edges
// more efficient logic: you can not advance only if you stumble to 0 with no other alternative
//   therefore, it is enough to move back from the last node one position at a time
//   and check it you can hup over '0' only when you stumble into it
//   not (!) bad strategy: [10,0,1,1,1,1,2,0,10], there is no isolated islands
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // quadratic time solution:
        /*
        vector<bool> reacheable(nums.size());
        reacheable[0] = true;
        for(int pos=0; pos<nums.size(); ){
            for(int i=pos+1; i<nums.size() && i<=pos+nums[pos]; ++i)
                reacheable[i] = true;
            if(reacheable[nums.size()-1]) return true;
            ++pos;
            while( pos<nums.size() && !reacheable[pos] ) ++pos;
            if( pos == nums.size() )
                return false;
        }
        return true;
        */
        int last_reacheable = nums.size()-1;
        for(int pos=nums.size()-1; pos>=0; --pos){
            if( nums[pos] + pos >= last_reacheable ) last_reacheable = pos;
        }
        return last_reacheable == 0;
    }
};
