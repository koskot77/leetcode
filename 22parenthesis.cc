class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return vector<string>();
        if(n==1) return vector<string>({"()"});
        vector<string> prev = generateParenthesis(n-1);
        set<string> retval;
        for(int i=0; i<prev.size(); ++i)
            for(int j=0; j<prev[i].size(); ++j)
                retval.insert(prev[i].substr(0,j) + "()" + prev[i].substr(j));
        vector<string> retval2;
        copy(retval.begin(),retval.end(),back_inserter(retval2));
        return retval2;
    }
};
