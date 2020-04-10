#include<set>
#include<vector>
#include<algorithm>
#include<iostream>
#include<random>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        // maintain two pointers: last blue and first off
        // update both every time when switching on the first off
        vector<bool> state(light.size());
        int last_blue = 0, first_off = 0, retval = 0;
        for(auto cur : light){
            --cur;
            if( cur == first_off ){
                int pos=first_off+1;
                while( pos < light.size() &&  state[pos] ) ++pos;
                if( pos == light.size() ) return retval+1;
                first_off = pos;
                last_blue = pos-1;
                while( pos < light.size() && !state[pos] ) ++pos;
                if( pos == light.size() ) ++retval;
            }
            state[cur] = true;
        }
        return retval;
    }
};

class Solution2 {
public:
    int numTimesAllBlue(vector<int>& light) {
        // maintain two pointers: last blue and first off
        // update both every time when switching on the first off
        int last_blue = 1, first_off = 1, retval = 0;
        set<int> turned_off(light.begin(),light.end());
        for(auto cur : light){
            turned_off.erase(cur);
            if( cur == first_off ){
                set<int>::const_iterator next_off = turned_off.lower_bound(cur);
                if( next_off == turned_off.end() ) return retval+1;
                first_off = *next_off;
                last_blue = first_off-1;
                if( turned_off.size() == light.size() - first_off+1 ) ++retval;
            }
        }
        return retval;
    }
};

int main(int argc, char *argv[]){
    size_t size = atoi(argv[1]);
    vector<int> light(size);
    iota(light.begin(), light.end(), 1);
    std::default_random_engine rState(0);
//    std::shuffle(light.begin(), light.end(), rState);
    Solution2 s;
    std::cout << s.numTimesAllBlue(light) << std::endl;
    return 0;
}
