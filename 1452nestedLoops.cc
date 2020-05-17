// error: don't overoptimise, it was not needed
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        // nested loops - N^2 * M runtime
        //  first, compose a dict for fast lookups:
        set<string> dict[favoriteCompanies.size()];
        for(int p=0; p<favoriteCompanies.size(); ++p)
            for(const auto &c : favoriteCompanies[p])
                dict[p].insert(c);

        vector<bool> unique(favoriteCompanies.size(),true);

        // now compare all with all
        for(int p1=0; p1<favoriteCompanies.size(); ++p1){
            for(int p2=p1+1; p2<favoriteCompanies.size(); ++p2){
                bool p2_subset_of_p1 =
                    includes(dict[p1].cbegin(), dict[p1].cend(),
                             dict[p2].cbegin(), dict[p2].cend());
                bool p1_subset_of_p2 =
                    includes(dict[p2].cbegin(), dict[p2].cend(),
                             dict[p1].cbegin(), dict[p1].cend());
                if( p1_subset_of_p2 ) unique[p1] = false;
                if( p2_subset_of_p1 ) unique[p2] = false;            
            }
        }
        vector<int> retval;
        for(int p=0; p<favoriteCompanies.size(); ++p)
            if( unique[p] ) retval.push_back(p);
        return retval;
        // better approach -> one-HOT encoding 
    }
};
