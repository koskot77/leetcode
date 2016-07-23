#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if( s.length() == 0 ) return string();

        // counts of types of chars for look-ahead logic
        int count[255] = {0};
        for(int i=0; i<s.length(); i++)
            count[ s[i] ] ++;

        // dismiss symbols that has already been used
        bool seen[255] = {false};

        // return value
        string retval;

        // the idea is that we keep looking for smallest symbol until we have no more spares for some other symbol ahead
        for(int i=0, minPos=0; i<s.length(); i++){
            // look for not yet seen smallest symbol
            if( s[minPos] > s[i] && seen[ s[i] ] == false ) minPos = i;
            // if the current symbol is the only of this kind or this is eos, place the smallest symbol in retval
            if( ( count[ s[i] ] == 1 && seen[ s[i] ] == false ) || i == s.length()-1 ){
                if( seen[ s[minPos] ] == false ) retval.append( 1, s[minPos] );
                seen[ s[minPos] ] = true;
                // restore the original counters between the curent position and minPos exclusively as we rewind back to minPos
                for(int j=minPos+1; j<i; j++)
                    count[ s[j] ]++;
                // rewind to the next after minPos symbol
                i = minPos;
                minPos++;
            } else 
                count[ s[i] ]--;
        }

        return retval;
    }
};

int main(void){
    Solution s;
    cout<< s.removeDuplicateLetters(string("cbacdcbc")) << endl;
    return 0;
}
