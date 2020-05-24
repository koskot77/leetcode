// https://leetcode.com/problems/rearrange-words-in-a-sentence
// error #0: now strtok strsep by hard
// error #1: watch your pos
// error #2: map iterator is not modifiable (?), better code
class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> corpus;
        for(string::size_type pos = 0; pos < text.length(); ){
            string::size_type end = text.find(' ', pos);
            if( end == string::npos ) end = text.length();
            corpus[end-pos].push_back(text.substr(pos,end-pos));
            pos = end + 1;
        }
        string retval;
        for(auto x : corpus)
            for(auto y : x.second){
                y[0] = tolower(y[0]);
                retval += y;
                retval += " ";
            }
        retval[0] = toupper(retval[0]);
        return retval.substr(0,retval.length()-1);
    }
};
