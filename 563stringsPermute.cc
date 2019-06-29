class Solution {
public:
    
    bool isPermutation(string s1, string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1 == s2;
    }
    
    bool checkInclusion(string s1, string s2) {
        // move over s2, select windows of len(s1), check is if the two are permutations
        if( s1.length() > s2.length() ) return false;
        if( s1.length() == 0 ) return true;

        unordered_map<char,int> lut1;
        for(int pos=0; pos<s1.length(); ++pos) ++lut1[s1[pos]];

        unordered_map<char,int> lut2;
        for(int pos=0; pos<s1.length(); ++pos) ++lut2[s2[pos]];
        
        if( lut1 == lut2 ) return true;
        
        for(int pos=1; pos<=s2.length()-s1.length(); ++pos){
            //if( isPermutation(s1,s2.substr(pos,s1.length())) ) return true;
            if(--lut2[s2[pos-1]] == 0 ) lut2.erase(s2[pos-1]);
            ++lut2[s2[s1.length()+pos-1]];
            if( lut1 == lut2 ) return true;
        }

        return false;
    }
};
