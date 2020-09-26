// conceptual errors:
//  1) simplify brutforce
//  2) think of end of recursion
class Solution {
public:
    int helper(string s, unordered_set<string> variants)
    {
        int retval = 0;
        for(int pos = 1; pos <= s.length(); ++pos)
        {
            string head = s.substr(0,pos); // error #1
            if( !variants.insert(head).second ) continue;
            if( s.length()==pos ) return max(retval,1); // error #2
            int res = helper(s.substr(pos,s.length()-pos), unordered_set<string>(variants));
            variants.erase(head);
            if( res == 0 ) continue;
            retval = max(retval, 1+res);
        }
        return retval;
    }
    
    int maxUniqueSplit(string s)
    {
        unordered_set<string> variants;
        return helper(s, variants);
    }
};
