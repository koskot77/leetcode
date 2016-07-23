#include<vector>
#include<iostream>
using namespace std;

class Solution {
//private:
public:
    vector<int> array;

    int choosePivot(int N){
        return 0;
    }

    void swap(int i, int j){
        int tmp  = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    void partition(int pivotPos, int begin, int end, int orderStat){ // end - next to last element
        // guard against nonesense
        if( begin < 0        || end>array.size() ||
            pivotPos < begin || pivotPos >= end  ||
            orderStat < 0    || orderStat > end  || 
            begin >= end ) return; // better use some eror code here

        // base recursion cases:
        //  one element array - nothing to do
        if( end == begin+1 ) return;
        //  swap two elements if needed
        if( end == begin+2 ){
            if( array[begin] > array[end-1] ) swap(begin,end-1);
            return;
        }

        // start from start
        swap(begin,pivotPos);
        int i = begin+1, j = begin+1;
        while( i < end && j < end ){
            if( array[i] >= array[begin] ){
                i++;
            } else {
                swap(i,j);
                i++;
                j++;
            }
        }
        swap(begin,j-1);

        // how far we are from the goal
        if( orderStat == j-1-begin ){ // bingo
            return;
        }

        if( orderStat <  j-1-begin ){ // recure on the left side subarray
            int newPivotPos = choosePivot(j-1-begin) + begin;
            partition(newPivotPos, begin, j-1, orderStat);
        }

        if( orderStat >  j-1-begin ){ // recure on the right side subarray
            int newPivotPos = choosePivot(end-j) + j;
            partition(newPivotPos, j, end, orderStat-(j-1-begin)-1);
        }
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        //typical quick select algorithm        
        array = nums;
        partition( choosePivot(array.size()), 0, array.size(), array.size()-k);
        return array[array.size()-k];
    }
};

int newIndex(int index, int n) {
        return (1 + 2*index) % (n | 1);
}


int main(void){

    Solution s;
    vector<int> array;
/*    array.push_back(3);
    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
    array.push_back(2);
    array.push_back(4);
    array.push_back(5);
    array.push_back(5);
    array.push_back(6);
    array.push_back(7);
    array.push_back(7);
    array.push_back(8);
    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
    array.push_back(1);
    array.push_back(1);
    array.push_back(10);
    array.push_back(11);
    array.push_back(5);
    array.push_back(6);
    array.push_back(2);
    array.push_back(4);
    array.push_back(7);
    array.push_back(8);
    array.push_back(5);
    array.push_back(6);
    cout << s.findKthLargest(array,2) << endl;
*/
/*
    array.push_back(1);
    array.push_back(3);
    array.push_back(2);
    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
*/
    array.push_back(1);
    array.push_back(2);
    array.push_back(2);
    array.push_back(1);
    array.push_back(2);
    array.push_back(1);
    array.push_back(1);
    array.push_back(1);
    array.push_back(1);
    array.push_back(2);
    array.push_back(2);
    array.push_back(2);


    cout << s.findKthLargest(array,array.size()/2) << endl<<endl;

    for(int i=0; i<s.array.size(); i++) cout<<s.array[i]<<","<<endl;
    cout<<endl;

        int n = s.array.size();
        int median = s.array[ n/2 ];
        int left = 0, i = 0, right = n - 1;

        while (i <= right) {

            if (s.array[newIndex(i,n)] > median) {
                s.swap(newIndex(left++,n), newIndex(i++,n));
            }
            else if (s.array[newIndex(i,n)] < median) {
                s.swap(newIndex(right--,n), newIndex(i,n));
            }
            else {
                i++;
            }
        }

    for(int i=0; i<s.array.size(); i++) cout<<s.array[i]<<","<<endl;
    cout<<endl;

return 0;
    // the first element should always be a small one
    //  last element should be a big one is array is even-sized, otherwise a small one
    int oddLen = s.array.size()%2;
    for(int pos=1; pos<s.array.size()/2; pos+=2)
        s.swap(pos,s.array.size()-1-pos + oddLen );

    for(int i=0; i<s.array.size(); i++) cout<<s.array[i]<<","<<endl;
    cout<<endl;

    // the only potential problem remaining is if the median element is followed_by/precedeed_by the same number
    int medPos = s.array.size()/2;
    if( (  oddLen && s.array[ medPos ] == s.array[ medPos + 1 ] ) ||
        ( !oddLen && s.array[ medPos ] == s.array[ medPos - 1 ] ) ){

        for(int pos=0; pos<s.array.size(); pos++){
            if( pos%2 ){ // a big number

                if( oddLen ){
                    if( ( pos == s.array.size() - 1 || s.array[ medPos+1 ] > s.array[ pos + 1 ] ) &&
                        ( pos == 0                  || s.array[ medPos+1 ] > s.array[ pos - 1 ] ) &&
                        ( s.array[ pos ] > s.array[ medPos ] && s.array[ pos ] > s.array[ medPos + 2 ] ) ){
                         s.swap( medPos+1, pos );
                         break;
                    }
                } else {
                    if( ( pos == s.array.size() - 1 || s.array[ medPos-1 ] > s.array[ pos + 1 ] ) &&
                        ( pos == 0                  || s.array[ medPos-1 ] > s.array[ pos - 1 ] ) &&
                        ( s.array[ pos ] > s.array[ medPos ] && s.array[ pos ] > s.array[ medPos - 2 ] ) ){
                         s.swap( medPos-1, pos );
                         break;
                    }
                }

            } else { // a small number

                if( ( pos == s.array.size() - 1 || s.array[ medPos ] < s.array[ pos + 1 ] ) &&
                    ( pos == 0                  || s.array[ medPos ] < s.array[ pos - 1 ] ) &&
                    ( s.array[ pos ] < s.array[ medPos-1 ] && s.array[ pos ] < s.array[ medPos + 1 ] ) ){
                    s.swap( medPos, pos );
                    break;
                }
 
            }

        }

    }

    for(int i=0; i<s.array.size(); i++) cout<<s.array[i]<<","<<endl;
    cout<<endl;

/*

    if( s.array.size()%2 ){
        s.swap(s.array.size()/2, s.array.size()-1);
    } else {
        for(int i=s.array.size()/2; i<s.array.size()-1; i++)
            s.swap(i-1,i);
    }

    for(int i=0; i<s.array.size(); i++) cout<<s.array[i]<<","<<endl;
*/
    return 0;
}
