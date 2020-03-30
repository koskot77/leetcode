

#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

    string rankTeams(vector<string>& votes) {
        // math.pow(26,26) == 6.156119580207158e+36
        // math.pow(2,128) == 3.402823669209385e+38 <- the above fits in two long longs
        // math.pow(26,13) == 2.4811528732037366e+18
        // math.pow(2,64)  == 1.8446744073709552e+19 <- the above fits in one long long
        std::map<char,std::pair<unsigned long long, unsigned long long>> teams;
        int s = votes.size();
        for(auto v:votes){
            for(int pos=0; pos<v.length(); ++pos){
            if( (v.length()-pos-1) < 13 ) // error1: screwed this one bad time
                    teams[v[pos]].second += pow(26,(v.length()-pos-1));
                else {
                    teams[v[pos]].first  += pow(26,(v.length()-pos-1)-13);
                    teams[v[pos]].second += pow(26,(v.length()-pos-1)%13);
                }
            }
        }
        std::vector<std::pair<char,std::pair<unsigned long long, unsigned long long>>> flat;
        flat.reserve(26);
        for(auto t:teams) flat.push_back(t);
        std::sort(flat.begin(),flat.end(),
            [](auto a,auto b){
                return a.second.first< b.second.first ||
                      (a.second.first==b.second.first && a.second.second< b.second.second) ||
                      (a.second.first==b.second.first && a.second.second==b.second.second && a.first > b.first);}); // error2: forgot

        std::string retval;
        for(auto a:flat){
            retval.insert(0,1,a.first);
        }
        return retval;
    }

int main(void){
vector<string> input = {"BCA","CAB","CBA","ABC","ACB","BAC"};

std::cout << rankTeams(input) << std::endl;

return 0;
}
