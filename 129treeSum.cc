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
    void helper(TreeNode *node, int sum, int& total_sum){
        if( node == NULL ) return;
        sum *= 10;
        sum += node->val;
        if( node->left == NULL && node->right == NULL ){
            total_sum += sum;
            return;
        }
        if( node->left ) helper(node->left, sum, total_sum);
        if( node->right) helper(node->right,sum, total_sum);
    }
    int sumNumbers(TreeNode* root) {
        int retval = 0;
        helper(root, 0, retval);
        return retval;
    }
};
