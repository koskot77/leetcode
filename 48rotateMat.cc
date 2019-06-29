class Solution {
public:
    void rot(vector<vector<int>>& m, int s){
        if( s == m.size()/2 ) return;
        int N = m.size() - s;
        for(int i=0; i<N-s-1; ++i){  // err #1: double-acting on last element
            int tmp       = m[s][i+s]; // err #2: define well N-1 wrt. i 
            m[s][i+s]     = m[N-i-1][s];
            m[N-i-1][s]   = m[N-1][N-i-1];
            m[N-1][N-i-1] = m[i+s][N-1];
            m[i+s][N-1]   = tmp;            
        }
        rot(m,s+1);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        rot(matrix,0);
    }
};
