["gb","gbb","hibefhcdihiefeaafhdi","fiifeffjahcjb","beecefcgfbcfg","f","hdacah","jfgbchcfiaec","diahgecaiegaeci","cebgegieagcfiijded"]
["gb","gbb","cgaadh","fii","jhce","a","ehhjge","aibibddfhjccfdgbe","egibfdbbebjjcb","hhiefg","fejeceieajfaaiccfe","jichjegdajcaeed","fihbbi","eacchjdafc","ggfijahidch","egeibcchfaj","hcaeihcjdibfdighc","djbddgcdchcb","hibefhcdihiefeaafhdi","fiifeffjahcjb","beecefcgfbcfg","f","hdacah","jfgbchcfiaec","diahgecaiegaeci","cebgegieagcfiijded"]
class Solution {
public:
    struct TrieNode {
        std::unordered_map<char,std::unique_ptr<TrieNode>> children;
        int end;
        TrieNode(void){ end = -1; }
    };
    bool isPalindrome(const std::string& word){
        if(word.empty()) return true;
        std::string drow = word;
        std::reverse(drow.begin(), drow.end());
        if( word == drow ) return true;
        return false;
    }
    struct Trie {
        TrieNode *root;
        void add(const std::string& word, int index){
            TrieNode *node = root;
            for(auto w : word){
                auto hit = node->children.find(w);
                if( hit != node->children.end() ){
                    node = hit->second.get();
                    continue;
                }
                node->children.insert( std::make_pair(w,new TrieNode()) );
                node = node->children[w].get();
            }
            node->end = index;
        }
        int find(const std::string& word){
            TrieNode *node = root;
            for(auto w : word){
                auto hit = node->children.find(w);
                if( hit != node->children.end() )
                    node = hit->second.get();
                else
                    return -1;
            }
            return node->end;
        }
        Trie(void){ root = new TrieNode(); }
    };
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> retval;
        Trie trie;
        for(int i=0; i<words.size(); ++i) trie.add(words[i], i);
        for(int i=0; i<words.size(); ++i){
            std::string cpy = words[i];
            std::reverse(words[i].begin(),words[i].end());
            for(int j=0; j<words[i].length(); ++j){
                int k=-1;
                if( isPalindrome(words[i].substr(j+1)) &&
                    (k = trie.find(std::string(words[i],0,j+1))) >=0 ){
                    if( i != k ){
                        std::vector<int> a;
                        a.push_back(k);
                        a.push_back(i);
                        retval.push_back(a);
                    }
                }
                if( isPalindrome(cpy.substr(j+1)) &&
                    (k = trie.find(std::string(cpy,0,j+1))) >=0 ){
                    if( i != k ){
                        std::vector<int> a;
                        a.push_back(i);
                        a.push_back(k);
                        retval.push_back(a);
                    }
                }
            }
        }
        return retval;
