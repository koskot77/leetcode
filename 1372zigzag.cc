// error1: this was a simple tree traversal problem!
// error2: overengeneered -> not brainsize
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
    void traverse(TreeNode *node, bool left, int &acc){
        int counter_left = 0, counter_right = 0;
        if( node->left!=NULL ){
            if( left ) counter_left = acc+1; else counter_left = 1;
            traverse(node->left,  false, counter_left);
        }
        if( node->right!=NULL ){
            if( !left ) counter_right = acc+1; else counter_right = 1;
            traverse(node->right, true,  counter_right);
        }
        int winner = std::max(counter_left, counter_right);
        acc = std::max(winner,acc);
    }

    int longestZigZag(TreeNode* root) {
        if( root == NULL ) return 0;
        int acc_l = (root->left!=NULL ? 1 : 0);
        if( acc_l) traverse(root->left,false,acc_l);
        int acc_r = (root->right!=NULL ? 1 : 0);
        if( acc_r ) traverse(root->right,true,acc_r);
        return std::max(acc_l,acc_r);
    }
};
