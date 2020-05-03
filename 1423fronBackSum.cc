class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // sequence doesn't metter, you take N from front and M from back (N+M==k)
        // you need to do it in linear time
        // what if k > cardPoints.size()?
        if( k>cardPoints.size() ) return 0;
        int score = 0;
        for(int i=0; i<k; ++i)
            score += cardPoints[i];
        int best_score = score;
        for(int i=k-1,j=0; i>=0; --i,++j){
            score -= cardPoints[i];
            score += cardPoints[cardPoints.size()-1 - j];
            if( score > best_score )
                best_score = score;
        }
        return best_score;
    }
};
