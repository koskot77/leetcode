/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *node, vector<int>& retval, int level){
        if( node == NULL ) return;
        if( retval.size() == level ) retval.push_back(node->val);
        else retval[level] = node->val;
        helper(node->left,  retval, level+1);
        helper(node->right, retval, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> retval;
        helper(root,retval,0);
        return retval;
    }
};
