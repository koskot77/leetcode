/// https://discuss.leetcode.com/topic/61473/annotated-greedy-c-solution
#include<string>
#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<climits>
#include<vector>
#include<math.h>
using namespace std;

class BruteForce {
private:
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

public:
    unsigned long removeKdigits(string num, int k){
        int length = num.size();
        unsigned long best = ULONG_MAX;
        vector<int> variants = NchooseM(length, k);
        for( vector<int>::const_iterator v = variants.begin(); v != variants.end(); v++ ){
            string trial = num;
            for(int j=length-1; j>=0; j--)
                if( *v & (1<<j) ) trial.erase(j,1);
            if( best > strtoul( trial.c_str(), NULL, 10 ) )
                best = strtoul( trial.c_str(), NULL, 10 );
        }
        return best;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        // the reasoning on weather the greedy solution works starts with an
        //  observation that removing _a_ vs. removing _b_ in the number
        //  "[.1.]a[.2.]b[.3.]" doesn't change blocks "[.1.]" and "[.3.]"
        // therefore the choice between eliminating _a_ vs. _b_ is made based
        //  on comparison of "[.2.]b" with "a[.2.]" or, equivalently, digit
        //  _a_ and the following digit from block "[.2.]" (consider no ties)
        // in other words we need to scan the _num_ from the most significant
        //  (left-most) side looking for sequential pairs _ab_ where _a_>_b_
        //  and drop _a_ until we exhaust _k_

        // check the trivial cases first
        if( num.size() <= k ) return "0";
        if( k <= 0 ) return num;

        // look for the first left-most case of decreasing _ab_ sequence
        for(int pos=0; pos<num.size()-1 && k>0; ){
            if( num[pos] > num[pos+1] ){
                num.erase(pos,1);
                pos = 0; // start over for simplicity
                k--;
            } else
                pos++;
        }

        // still need to delete something? chop "biggest" digits from the tail
        num.erase( num.size()-k, k );

        // drop leading zeros
        int pos = 0;
        for(; pos<num.size() && num[pos] == '0'; pos++);
        if( pos ) num.erase(0,pos);

        // yet another trivial case
        if( num.size() == 0 ) return "0";

        return num;
    }
};

int main(void){
    Solution s;
    BruteForce bf;
    const int toRemove = 5;

    for(int iter = 0; iter < 100000; iter++){
        unsigned long val = random();
        if( val < (pow(10,toRemove) - 1) ) continue;
        stringstream line;        
        line << val;
        string res = s.removeKdigits(line.str(),toRemove);
        unsigned long ref = bf.removeKdigits(line.str(),toRemove);
        if( ref != strtoul( res.c_str(), NULL, 10 ) )
            cout << "Val="<< val << " res=" << res << " ref=" << ref << endl;
    }

    //cout << res << endl;
    return 0;
}
