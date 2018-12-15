#include<list>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

// g++ -std=c++11 -g -o test 948doubledPairs.cc

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if( A.size() % 2 ) return false;
        list<int> B;
        copy(A.begin(), A.end(), back_inserter(B));
        B.sort([](int e1, int e2){ return abs(e1)<abs(e2); });

        unordered_multimap<int, list<int>::iterator> C;
        for(list<int>::iterator it=B.begin(); it!=B.end(); ++it)
            C.insert(make_pair(*it,it));

        while(B.size()){
            int e = *B.rbegin();
            if( e % 2 ) return false;
            unordered_multimap<int,list<int>::iterator>::const_iterator e1 = C.find(e);
            unordered_multimap<int,list<int>::iterator>::const_iterator e2 = C.find(e/2);
            if( e1 == C.end() || e2 == C.end() ) return false;
            // zero is a special case
            if( e1 == e2 && (++e2 == C.end() || e2->first != 0) ) return false;
            B.erase( e1->second );
            B.erase( e2->second );
            C.erase(e1);
            C.erase(e2);
        }
            
        if( B.size() ) return false;
        return true;
    }
};

int main(void){
//    vector<int> input({1,2,4,8});
//    vector<int> input({1,2,4,16,8,4});
    vector<int> input({4,-2,2,-4});
    Solution s;
    std::cout << s.canReorderDoubled(input) << std::endl;
    return 0;
}
