class Solution {
public:
    vector<int> grayCode(int n) {
        if( n == 0 ) return vector<int>({0});
        vector<int> res = grayCode(n-1);
        vector<int> retval;
        copy(res.begin(), res.end(), back_inserter(retval));
        for(int i=res.size()-1; i>=0; --i)
            retval.push_back((1<<(n-1)) | res[i]);
        return retval;
    }
};
