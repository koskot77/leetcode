#include<set>
#include<vector>
#include<string>
#include<iostream>
#include<string.h>

// g++ -g -std=c++11 -o test 955deleteSortingII.cc

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // sanity
        if( A.size() == 0 ) return 0;
        size_t s = A[0].length();

        // Basics:
        //  1) delering a column doesn't change the sorting order
        //     of the already sorted rows
        //  2) if A[i+0] <= A[i+1] and A[i+1] <= A[i+2] then
        //     automatically A[i+0] <= A[i+2]
        // Therefore, operate on an adjacent pair and advance
        
        set<size_t> to_delete;
        // advance pairs
        for(size_t step=1; step<A.size(); ++step) {
            // alanyse the pair
            for(size_t pos=0; pos<s; ++pos){
                if( to_delete.find(pos) != to_delete.end() )
                    continue;
                if( strncmp(&A[step-1][pos],&A[step][pos],1) < 0 )
                    break;
                if( strncmp(&A[step-1][pos],&A[step][pos],1) > 0 ){
                    to_delete.insert(pos);
                    step = 0;
                    break;
                }
            }
        }

        return to_delete.size();   
    }
};


int main(void)
{

vector<string> input(
{"vkpphftpeutkfbrlbmqmahunjgeaol","fprnxczfmzcethrhhnujagbkcqjopp","yivlvyuxtnpwpsgpjejmmcykjkggnw","gjegryvechocvjsrnfykeywfcwenlx","ntfvoekvlpmoorosprmozdduzzxmsk","lsksvvpxxoludxxltlakelxxnfieiu","cegqlvawbdwzazpqtlusqhbfymytxz","kandmcbmxijbtasuvaraecglrhxsgg","yhjzmmfkwqfwavnrvokzckhugsdzbm","ivgpveqosuslpamnyaifdnbliwndhv"} );

Solution s;
std::cout << s.minDeletionSize(input) << std::endl;

return 0;
}
