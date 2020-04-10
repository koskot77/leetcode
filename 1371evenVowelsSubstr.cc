#include<string>
#include<vector>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        // ugly quadratic time
        size_t len = s.length();
        vector<int> a(len+1), e(len+1), i(len+1), o(len+1), u(len+1);
        vector<int> A(len+1), E(len+1), I(len+1), O(len+1), U(len+1);
        for(int pos=0; pos<len; ++pos){
            switch( s[pos] ){
                case 'a': ++A[pos+1]; break;
                case 'e': ++E[pos+1]; break;
                case 'i': ++I[pos+1]; break;
                case 'o': ++O[pos+1]; break;
                case 'u': ++U[pos+1]; break;
                default: break;
            }
        }
  
        std::partial_sum(A.begin(), A.end(), a.begin());
        std::partial_sum(E.begin(), E.end(), e.begin());
        std::partial_sum(I.begin(), I.end(), i.begin());
        std::partial_sum(O.begin(), O.end(), o.begin());
        std::partial_sum(U.begin(), U.end(), u.begin());

        int best_pos_right = 0, best_pos_left = 0;
        for(int pos1=len; pos1>=0; --pos1){
            for(int pos2=0; pos2<pos1; ++pos2){
                if( (a[pos1]-a[pos2])%2 == 0 &&
                    (e[pos1]-e[pos2])%2 == 0 &&
                    (i[pos1]-i[pos2])%2 == 0 &&
                    (o[pos1]-o[pos2])%2 == 0 &&
                    (u[pos1]-u[pos2])%2 == 0 ){
                    if( best_pos_right - best_pos_left < pos1 - pos2 ){
                        best_pos_right = pos1;
                        best_pos_left  = pos2;
                    }
                    break;
                }
            }        
        }
        return best_pos_right - best_pos_left;
    }
};

int main(void){
  Solution s;
  std::cout << s.findTheLongestSubstring("bcbcbc") << std::endl; // "leetcodeisgreat" "eleetminicoworoep"
  return 0;
}
