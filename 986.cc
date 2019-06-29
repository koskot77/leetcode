class Solution {
public:
    int brokenCalc(int X, int Y) {
        if( Y <= X )
            return X - Y;

        float p = log2(float(Y)/X);
        if( p == int(p) ) 
            return p;

        int pp = int(p) + 1;
        int max = X * (1 << pp);

        int best[max+1];
        for(int i=X, j=0; i>=0; --i,++j)
            best[i] = j;
        
        for(int i=1; i<=pp; ++i)
        {
            best[X*(1 << i)] = i;
            for(int j=X*(1<<i)-1; j>X*(1<<(i-1)); --j)
            {
                if( (j%2) == 0)
                    best[j] = min(best[j+1],best[j/2]) + 1;
                else
                    best[j] = best[j+1] + 1;
            }
        }

        return best[Y];
    }
};
