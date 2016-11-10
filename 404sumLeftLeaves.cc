// https://leetcode.com/problems/sum-of-left-leaves/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if( root == NULL ) return 0;
        int retval = ( root->left != NULL && root->left->left == NULL && root->left->right == NULL ? root->left->val : 0 ) ;
        retval += sumOfLeftLeaves(root->left);
        retval += sumOfLeftLeaves(root->right);
        return retval;
    }
};
