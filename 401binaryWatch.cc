// https://leetcode.com/problems/binary-watch/
// https://discuss.leetcode.com/topic/61200/annotated-c-solution-calculating-all-led-permutations
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    // this function returns an exhaustive list of permutations of _m_ elements in _n_ "buckets"
    // because the space of this problem is limited to 6 elements max we enumerate the permutations
    //  with integer numbers (plenty of space even with 32 bits)
    // the main loop starts with the first _m_ bits set to 1 (the rest are 0s)
    // then it shifts the most significant bit (MSB) sequentially over the remaining _n_-_m_
    //  positions and makes a recursive call on a smaller subproblem bounded by the current
    //  position of the MSB and permuting the remaining _m_-1 bits

    vector<int> NchooseM(int n, int m){
        vector<int> retval;
        if( n==0 ){ retval.push_back(0); return retval; }
        if( m==0 ){ retval.push_back(0); return retval; }
        if( n==m ){ retval.push_back((1<<n)-1); return retval; }

        // start with _m_th element in its initial m-1 position and shift is to the last n-1 "bucket"
        for(int pos=m-1; pos<n; pos++){
            // solve smaller problem with _m_-1 elements permuted in _pos_ "buckets"
            vector<int> sub = NchooseM(pos,m-1);
            // note the current MSB position
            for(auto i: sub)
                retval.push_back( (1<<pos) + i );
        }
        return retval;
    }

    // make short Look Up Tables for fast conversion of the limited number of cases here
    const char* hourToString(int i){
        if( i<0 || i>11 ) return 0;
        const char *hours[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};
        return hours[i];
    }

    const char* minToString(int i){
        if( i<0 || i>59 ) return 0;
        const char *minutes[] = {
               "00","01","02","03","04","05","06","07","08","09",
               "10","11","12","13","14","15","16","17","18","19",
               "20","21","22","23","24","25","26","27","28","29",
               "30","31","32","33","34","35","36","37","38","39",
               "40","41","42","43","44","45","46","47","48","49",
               "50","51","52","53","54","55","56","57","58","59"
        };
        return minutes[i];
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> retval;
        // safety check
        if( num > 10 ) return retval;
        // split LEDs between hours and minutes
        for(int h=( num-6<=0 ? 0 : num-6 ); h<=4 && h<=num; h++){
            // at this point we have a fixed number of LEDs for representing hours (h) and minutes (num-h)
            // now generate all NchooseM combinations for each and combine
            vector<int> hours = NchooseM(4,h);
            vector<int> mins  = NchooseM(6,num-h);
//            cout<<"h="<<h<<" hours="<<hours.size()<<" mins="<<mins.size()<<endl;
            for(auto hh: hours)
                for(auto mm: mins){
                    if( hh<12 && mm<60 )
                        retval.push_back( string(hourToString(hh)) + ":" + minToString(mm) );
                }
        }
        return retval;
    }
};

int main(void){
    Solution s;
//    cout<<"size: "<<s.NchooseM(20,10).size()<<endl;
//    return 0;
    vector<string> a = s.readBinaryWatch(0);
    for(auto i: a){
        cout<<i<<endl;
    }
    return 0;
}
