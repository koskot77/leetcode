// Bruteforce recursion:
//   chop off first number and give the tail to itself (function that returns all increasing subsequences of the tail
//   return resulting list augmented with all valid subsequences including the chopped off head
class Solution {
public:
    set<list<int>> helper(list<int> &nums){
        if(nums.size() == 1) return set<list<int>>{{nums.front()}};
        int head = nums.front();
        nums.pop_front();
        set<list<int>> ss = helper(nums);
        set<list<int>> retval(ss);
        for(auto s:ss){
            if( head <= s.front() ){
                s.push_front(head);
                retval.insert(s);
            }
        }
        retval.insert({head}); // error: don't forget to seed the head
        return retval;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.size()==0) return vector<vector<int>>();
        list<int> nn(nums.cbegin(),nums.cend());
        set<list<int>> res = helper(nn);
        vector<vector<int>> retval;
        for(auto &r:res){
            if( r.size() < 2 ) continue;
            retval.push_back(vector<int>());
            auto &rv = retval.back();
            for(auto rr:r)
                rv.push_back(rr);
        }
        return retval;
    }
};
