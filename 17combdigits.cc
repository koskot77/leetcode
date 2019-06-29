class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if( digits.length() == 0 )
            return vector<string>();
        vector<string> lut[256];
        lut['2'] = vector<string>({"a","b","c"});
        lut['3'] = vector<string>({"d","e","f"});
        lut['4'] = vector<string>({"g","h","i"});
        lut['5'] = vector<string>({"j","k","l"});
        lut['6'] = vector<string>({"m","n","o"});
        lut['7'] = vector<string>({"p","q","r","s"});
        lut['8'] = vector<string>({"t","u","v"});
        lut['9'] = vector<string>({"w","x","y","z"});
        if( digits.length() == 1 ) return lut[digits[0]]; // err #0
        vector<string> sub = letterCombinations(digits.substr(1));
        vector<string> retval;
        for(int i=0; i<sub.size(); ++i)
        {
            for(int j=0; j<lut[digits[0]].size(); ++j)
            retval.push_back(lut[digits[0]][j] + sub[i]);
        }
        return retval;
    }
};
