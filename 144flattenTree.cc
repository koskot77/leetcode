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
    void flatten(TreeNode* root) {
        if( root == NULL ) return; // err #1
        TreeNode *left  = root->left;
        TreeNode *right = root->right;
        root->left = NULL;
        flatten(left);
        root->right = left;
        TreeNode *node = left;
        if( node ) // err #2
        while( node->right != NULL ) node = node->right;
        flatten(right);
        if( node )
        node->right = right;
        else root->right = right;
    }
};

