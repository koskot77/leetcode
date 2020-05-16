// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/submissions/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // (x^y)^z = x^(y^z)
        // 0^x = x -> x^(x^y^z) = y^z
        // x^x = 0 -> a==b -> a^b = 0
        // xor(i-k) = a^b
        // find all i,k that xor(i-k) == 0
        unordered_map<int,vector<int>> i_k; // cumulative xor to indices
        i_k[0].push_back(-1); // special case example: 3,3,3 has two solutions: (0,1,1) and (0,1,2)
        // error #1: there may also be 3,3,3,3 -> use vector for value of map
        // error #2: special case of xor = 0
        for(int pos=0, acc=0; pos<arr.size(); ++pos)
            i_k[acc ^= arr[pos]].push_back(pos);
        int retval = 0;
        for(auto r : i_k)
            for(int i=0; i<r.second.size(); ++i)
                for(int k=i+1; k<r.second.size(); ++k)
                    retval += r.second[k] - r.second[i] - 1; // so many j's

        return retval;
    }
};
