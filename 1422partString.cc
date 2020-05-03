class Solution {
public:
    int maxScore(string s) {
        int left_zeros = 0, right_ones = 0;
        for(int i=0; i<s.length(); ++i)
            if(s[i]=='1') ++right_ones;
        // left subarray has to be non-zero -> move pointer
        if( s[0]=='0' ) ++left_zeros; else --right_ones;
        int score = left_zeros + right_ones;
        for(int i=1; i<s.length()-1; ++i){
            if(s[i]=='0') ++left_zeros;
            else --right_ones;
            if( score < left_zeros + right_ones )
                score = left_zeros + right_ones;
        }
        return score;
    }
};
