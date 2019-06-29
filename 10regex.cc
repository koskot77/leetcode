#include<iostream>
#include<string>
#include<string.h>
#include<set>
using namespace std;

class Solution {
public:
    bool can_be_none(const char *p){
        while(*p != '\0' && p[1] == '*' ) p += 2;
        return *p=='\0';
    }

    bool helper(const char *s, const char *p, std::set<std::string>& lut, int depth) {

        if( lut.insert(std::string(s)+"_"+std::string(p)).second == false )
            return false;
        ++depth;
cout<< "s: " << s << " p: " << p << " depth: " << depth << endl;
        if( *s == '\0' && *p == '\0' ) return true;
        if( *s != '\0' && *p == '\0' ) return false;
        if( p[1] != '*' )
        {
            if( p[0] == s[0] || p[0] == '.' )
                return helper(s+1,p+1, lut, depth);
        }
        else
        {
            for(int i=0; s[i] != '\0'; ++i)
            {
                if( helper(s+i,p+2, lut, depth) ) return true;
                if( p[0] != '.' && s[i] != p[0] ) return false;
            }
            return helper("",p+2, lut, depth); // can_be_none(p+2);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        // edge case - nothing to do
        if( p.length() == 0 ){
            if(s.length() == 0 ) return true;
            else return false;
        }

        // check that everything expected is present
        char must_be_present[256];
        bzero(must_be_present,256);
        for(int i=0; i<p.length(); ++i)
            if( p[i] != '.' && p[i] != '*' ){
                if( i+1<p.length() && p[i+1] == '*' )
                    continue;
                ++must_be_present[p[i]];
            }
        char present[256];
        bzero(present,256);
        for(int i=0; i<s.length(); ++i)
            ++present[p[i]];
        for(int i=0; i<256; ++i)
            if( must_be_present[i] && !present[i] ) return false;

        // collapse bullshit like .*.*
        string p_collapsed;
        for(int i=0; i<p.length(); ){
            if( i+3<p.length() && p[i] == p[i+2] && p[i+1] == '*' && p[i+3] == '*'){
                i += 2;
                continue;
            }
            p_collapsed += p[i];
            ++i;
        }
        // heavy lifting
        std::set<std::string> lut;
        int depth = 0;
        return helper(s.c_str(),p_collapsed.c_str(), lut, depth);
    }
};

int main(void){
    Solution x;
    string s = "acaabbaccbbacaabbbb"; //"bccbbabcaccacbcacaa";
    string p = "a*.*b*.*a*aa*a*"; //".*b.*c*.*.*.c*a*.c";
    x.isMatch(s,p);
    return 0;
}
