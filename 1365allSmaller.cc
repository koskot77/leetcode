class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101] = {};
        for(auto i: nums) cnt[i]++;
        int cumsum[101] = {};
        for(int i=0, cs=0; i<101; ++i){ cumsum[i]=cs; cs += cnt[i]; }
        vector<int> retval;
        retval.reserve(nums.size());
        for(auto i: nums){ retval.push_back(cumsum[i]); }
        return retval;
/*        vector<int> sorted(nums);
        std::sort(sorted.begin(), sorted.end());
        vector<int> retval;
        retval.reserve(nums.size());
        for(auto i : nums){
            auto pos = std::lower_bound(sorted.begin(), sorted.end(), i);
            retval.push_back(std::distance(sorted.begin(),pos));
        }
        return retval;*/
    }
};
