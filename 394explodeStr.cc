class Solution {
public:
    string decodeString(string s) {
        int bra = 0;
        while( bra < s.length() && s[bra] != '[' ) ++bra;
        int ket = bra + 1, cnt = 0;
        while( ket < s.length() ){ // err #0: case
            if( s[ket] == ']' && cnt-- == 0 ) break;
            if( s[ket] == '[' ) ++cnt;
            ++ket;
        }
        if( bra == s.length() || ket == s.length() ) return s;
        string inside = decodeString(s.substr(bra+1,ket-bra-1));
        string replication;
        --bra;
        while( isdigit(s[bra]) )
        {
            replication.insert(0,s.substr(bra,1));
            if( --bra < 0 ) break; // err #1: accuracy
        }
        string retval = s.substr(0,bra+1); // ^^
        int rep = atoi(replication.c_str());
        for(int i=0; i<rep; ++i)
        {
                retval += inside;
        }
        retval += decodeString(s.substr(ket+1,s.length()-ket-1));
        return retval;
    }
};
