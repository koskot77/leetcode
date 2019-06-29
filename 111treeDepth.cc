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
    int minDepth(TreeNode* root) {
        if( root == NULL ) return 0;
        // err #1: define leaf
        if( root->left == NULL && root->right == NULL ) return 1;
        if( root->left != NULL && root->right == NULL ) return minDepth(root->left) + 1;
        if( root->left == NULL && root->right != NULL ) return minDepth(root->right) + 1;
        int dl = minDepth(root->left);
        int dr = minDepth(root->right);
        return dl>dr ? dr+1 : dl+1;
    }
};
