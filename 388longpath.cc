//https://leetcode.com/problems/longest-absolute-file-path/
//https://discuss.leetcode.com/topic/72000/tab-is-not-replaceable-with-4-spaces
#include<iostream>
#include<string>
#include<list>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input){
        int maxLength = 0;
        int curLength = 0;
        int curLevel  = 0;
        list<int> historyLength;
        for(size_t pos=input.find("\n"),prevPos=0,prevLen=0 ; ; prevLen=pos-prevPos,prevPos=pos,pos=input.find("\n",pos+1)){
            int level = 0;
            for(size_t p=prevPos+1; input[p]=='\t' || input[p]==' '; p++) level++;
            while( level < curLevel ){
                curLength = historyLength.back();
                historyLength.pop_back();
                curLevel -= (input[prevPos+1]=='\t' ? 1 : 4);
            }
            if( level > curLevel ){
                historyLength.push_back(curLength);
                curLength += prevLen-curLevel;
                curLevel   = level;
            }

            if( pos == string::npos ) pos = input.length();

            if( input.substr(prevPos,pos-prevPos).find(".") != string::npos ) // this is file
                if( maxLength < curLength + pos-prevPos-level )
                    maxLength = curLength + pos-prevPos-level;

            if( pos == input.length() ) break;
        }
        return maxLength;
    }
};

int main(void){
    Solution s;
    //int r = s.lengthLongestPath("dir\n    file.txt\n    dir2\n        file.txt");
    int r = s.lengthLongestPath("dir\n    file.txt");
    cout<<r<<endl;
    return 0;
}
