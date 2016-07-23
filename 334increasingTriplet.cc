#include<vector>
#include<iostream>
using namespace std;

    bool increasingTriplet(vector<int>& nums) {

        if( nums.size() < 3 ) return false;

        int i=0, j=1, k=2;

        while( i < nums.size()-2 && j<nums.size()-1 && k<nums.size() ){
            if( nums[i]  < nums[j] && nums[j] <  nums[k] ) return true;
            if( nums[i]  < nums[j] && nums[j] >= nums[k] ){
                if( k<nums.size()-1 ) k++;
                else {
                    if( j<nums.size()-2 ){
                        j++;
                        k = j+1;
                    } else {
                        i++;
                        j=i+1;
                        k=j+1;
                    }
                }
            } else {
                if( j<nums.size()-2 ){
                    j++;
                    k = j+1;
                } else {
                    i++;
                    j=i+1;
                    k=j+1;
                }
            }
        }
        return false;
    }

int main(void){
    vector<int> num;
    num.push_back(2);
    num.push_back(5);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);

    cout<<increasingTriplet(num)<<endl;

    return 0;
}
