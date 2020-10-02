/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *node, vector<int> &max_val, int depth){
        if( node == nullptr ) return;     
        if( max_val.size() <= depth ) max_val.push_back(node->val);
        else {
            max_val[depth] = max(max_val[depth], node->val);
        }
        helper(node->left,  max_val, depth+1);
        helper(node->right, max_val, depth+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> retval;
        helper(root, retval, 0);
        return retval;
    }
};
