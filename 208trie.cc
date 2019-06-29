class Trie {
public:
    struct TrieNode {
        std::unordered_map<char,TrieNode*> children;
        bool end;
        TrieNode(void){ end = false; }
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(int i=0; i<word.length(); ++i){
            auto hit = node->children.find( word[i] );
            if( hit != node->children.end() ){
                node = hit->second;
                continue;
            }
            node = (node->children[word[i]] = new TrieNode());
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(int i=0; i<word.length(); ++i){
            auto hit = node->children.find(word[i]);
            if( hit == node->children.end() ) return false;
            node = hit->second;
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(int i=0; i<prefix.length(); ++i){
            auto hit = node->children.find(prefix[i]);
            if( hit == node->children.end() ) return false;
            node = hit->second;
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
