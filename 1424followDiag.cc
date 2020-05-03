class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
/*        vector<int> retval;
        int total_len = 0, max_len = 0;
        for(int i=0; i<nums.size(); ++i){
            total_len +=  nums[i].size();
            if( max_len < nums[i].size() )
                max_len = nums[i].size();
        }
        // N*M algorithm:
        for(int slice=0; retval.size()<total_len; ++slice){
            for(int row=slice, col=0; row>=0; --row,++col){
                if( row >= nums.size() ){
                    col  = row - nums.size() + 1;
                    row  = nums.size()-1;
                }
                if( col > max_len ) break;
                if( nums[row].size()<=col ) continue;
                retval.push_back(nums[row][col]);
            }
        }
*/
        // linear time, but with extra space (error: after a hint!)
        vector<tuple<int,int,int>> extra;
        for(int i=0; i<nums.size(); ++i){
            for(int j=0; j<nums[i].size(); ++j){
                extra.push_back(make_tuple(i+j,j,nums[i][j]));
            }
        }
        sort(extra.begin(),
             extra.end(),
             [](auto x, auto y){ return get<0>(x)<get<0>(y) || (get<0>(x)==get<0>(y)&&get<1>(x)<get<1>(y)); }
            );
        vector<int> retval(extra.size());
        transform(extra.cbegin(), extra.cend(), retval.begin(), [](auto x){return get<2>(x);});
        return retval;
    }
};
