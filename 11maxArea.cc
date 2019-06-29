// err #0: not mine
//  guessed two pointers solution correctly, but didn't figure out how to move those
//  (it is counterintuitive to move the one that is bigger!)
//  general remark: moving two pointers exhaust all possible combinations here
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
//        for(int i=0; i<height.size(); ++i)
//            for(int j=i+1; j<height.size(); ++j){
//                int s = (j-i) * ( height[i]<height[j]?height[i]:height[j] );
//                if( s > max_area ) max_area = s;
//            }
        // typical two pointers problem?
        //  yes, but with an extra logic with regard to rationale of moving ptrs
        //  "if height[b] < height[e], moving e back doesn't help:
        //   height[e-1] decreases - can get worse, height[e-1] increases - no use"
        for(int b=0, e=height.size()-1; b<e; ){
            if( height[b] < height[e] ){
                int s = (e - b) * height[b];
                if( s > max_area ) max_area = s;
                ++b;
            } else {
                int s = (e - b) * height[e];
                if( s > max_area ) max_area = s;
                --e;
            }
        }
        return max_area;
    }
};
