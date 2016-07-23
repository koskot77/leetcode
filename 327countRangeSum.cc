#include<map>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
private:
    multimap<int64_t,int> hash;
    vector<int64_t> sums;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // preprocessing
        sums.clear();
        hash.clear();
        sums.push_back(0);
        for(int64_t i=0, sum=0; i<nums.size(); i++){
            sum += nums[i];
            sums.push_back( sum );
            hash.insert( pair<int64_t,int>(sum,i+1) );
cout<<sum<<endl;
        }
        // now a sum within an interval [i:j] is just sums[j]-sums[i-1] and the later should be between lower-upper
        // to have a quck check for the lower-upper interval we use ordered hash
        int retval = 0;
        for(int i=0; i<sums.size(); i++){
            int64_t s = sums[i];
            for( multimap<int64_t,int>::const_iterator it = hash.lower_bound( s + lower ); it != hash.end() && it->first - s <= upper ; it++ ){
               if( it->second > i ){
                   retval++;
                   cout<<"["<<i<<","<<it->second-1<<"]"<<endl;
               }
            }
        }
        return retval;
    }
};

int main(void){
    vector<int> input;
    input.push_back(-2147483647);
    input.push_back(0);
    input.push_back(-2147483647);
    input.push_back(2147483647);
    Solution s;
    cout << s.countRangeSum(input,-564,3864) << endl;

    return 0;
}
