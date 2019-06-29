class Solution {
public:
    struct TrieNode{
        unique_ptr<TrieNode> children[2];
    };
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode();
        for(auto &n : nums){
            TrieNode *node = root;
            for(int shift=31; shift>=0; --shift){
                TrieNode *next = node->children[ (n >> shift) & 0x1 ].get();
                if( next != 0 ) node = next;
                else {
                    node->children[(n >> shift) & 0x1].reset(new TrieNode());
                    node = node->children[(n >> shift) & 0x1].get();
                }
            }
        }
        int max_num = 0;
        for(auto n: nums){
            int m = 0;
            TrieNode *node = root;
            for(int shift=31; shift>=0; --shift){
                TrieNode *next = node->children[ ((n >> shift) & 0x1) ^ 0x1 ].get();
                if( next != 0 ){
                    m |= (1<<shift);
                    node = next;
                } else {
                    node = node->children[ ((n >> shift) & 0x1) ].get();
                }
            }
            if( m>max_num) max_num = m;
        }
        return max_num;
    }
};
