// the question is not how to do that (with a bit of bookkeeping you can do that)
// the question is how to do that efficiently
// 1  2  3  4  5
//16  .  .  .  6
//15  .  .  .  7
//14  .  .  .  8
//13 12 11 10  9
// looks like a pattern: the full circle fits N+N+N-2+N-2= 4*(N-1) elements
// and then we start with a smaller matrix inside that'll fit 4*(N-1-1) elements
// but the problem is not to find an element in a certain coordinate, or is it?
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // ok, solution with bookeeping:
        vector<vector<int>> retval(n);
        for(int i=0; i<n; ++i) retval[i].resize(n);
        for(int x=0, y=0, num=1, dir=0, off=0; n>0;){
            retval[y][x] = num++;
            if(num > n*n) break;
            switch(dir){
                case 0: if(++x == n-1-off) dir=1; break;
                case 1: if(++y == n-1-off) dir=2; break;
                case 2: if(--x == off    ) dir=3; break;
                case 3: if(--y == off+1 ){ dir=0; ++off; } break;
                default: break;
            }
        }
        return retval;
    }
};
