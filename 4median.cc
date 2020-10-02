// mergesort w/o keeping the result, home in to the middle, evaluate the median
// linear time - no scorring
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int middle = total/2, last_a = -10000000, last_b = -10000000;
        vector<int>::const_iterator a=nums1.cbegin(), b=nums2.cbegin();
        for(int i=0; i<middle; ++i){
            if( a == nums1.cend() ){
                last_b = *b++;
                continue;
            }
            if( b == nums2.cend() ){
                last_a = *a++;
                continue;
            }
            if( *a < *b )
                last_a = *a++;
            else
                last_b = *b++;
        }
        if( nums1.empty() ){
            if( total%2 ) return *b;
            else return (last_b+*b)/2.;
        }
        if( nums2.empty() ){
            if( total%2 ) return *a;
            else return (last_a+*a)/2.;
        }
        if( a==nums1.cend() ){
            if( total%2 ) return *b;
            else {if(last_b<-1000000) return (last_a+*b)/2.; else return (last_b+*b)/2.;}
        }
        if( b==nums2.cend() ){
            if( total%2 ) return *a;
            else {if(last_a<-1000000) return (last_b+*a)/2.; else return (last_a+*a)/2.;}
        }
        if( total%2 ){
            if( *a <= *b ) return *a; else return *b;
        } else {if( *a <= *b ) return (*a+last_b)/2.; else return (*b+last_a)/2.;}
        return -100000000;
    }
};
