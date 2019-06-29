class WordDictionary {
public:
    struct TrieNode {
        std::unordered_map<char, std::unique_ptr<TrieNode> > children;
        bool end;
        TrieNode(void){ end = false; }
    };
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for(int i=0; i<word.length(); ++i){
            auto hit = node->children.find(word[i]);
            if( hit != node->children.end() ){
                node = hit->second.get();
                continue;
            }
            node->children.insert(std::make_pair(word[i],new TrieNode()));
            node = node->children[word[i]].get();
        }
        node->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode *node = root;
        for(int i=0; i<word.length(); ++i){
            if( word[i] != '.' ){
                auto hit = node->children.find(word[i]);
                if( hit != node->children.end() ){
                    node = hit->second.get();
                    continue;
                }
                return false;
            } else {
                TrieNode *root_orig = root;
                for(auto child=node->children.begin(); child!=node->children.end(); ++child){
                    root = child->second.get();
                    if( search(word.substr(i+1)) ){
                        root = root_orig;
                        return true;
                    }
                }
                root = root_orig;
                return false;
            }
        }
        return node->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
