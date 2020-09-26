// two pointers defining the numbers to try:
// 199100199
//  ^ ^
// 1+99 ?= look for 100
// chop off q and start over
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if( num.empty() ) return false;
        for(int p1=1; p1<num.length(); ++p1){
            for(int p2=p1+1; p2<num.length(); ++p2){
                unsigned long long int n1 = strtoull(num.substr(0,p1).c_str(),NULL,10);
                unsigned long long int n2 = strtoull(num.substr(p1,p2-p1).c_str(),NULL,10);
                stringstream ss;
                ss << (n1+n2);
                string s = ss.str();
                if( num.substr(p2,s.length()).compare(s) == 0 && // error #2: remember compare signature
                   ( num.length() == p2+s.length() || isAdditiveNumber(num.substr(p1))) ){ // error #1: end of recursion
                    return true;
                }
                if(num[p1]=='0') break; // special condition
            }
            if( num[0]=='0' ) break; // special condition
        }
        return false;
    }
};
