// err #1: forget about std::algo, they turn simple problems ugly
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // another 3-pointer problem with "no other choise" as direction rationale
        sort(nums.begin(), nums.end());
        if( nums.size() < 3 ) return 0;
        int closest = nums[0]+nums[1]+nums[2], min_dist = 10000000;
        for(int k=0; k<nums.size(); ++k){
        int start = k+1;
        int finish = nums.size()-1;
        while(start < finish){
            int abc = nums[k] + nums[start] + nums[finish];
            if( abc < target ) ++start;
            if( abc > target ) --finish;
            if( abc == target) return target;
            if( abs(abc - target) < min_dist ){ // err #2: details
                min_dist = abs(abc - target);   //
                closest = abc;                  // err #3: order
            }
        }
        }
        return closest;
    }
};
