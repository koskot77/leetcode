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
    bool helper(TreeNode *node, int& depth){ // err #1: think what you want to check and return
        if( node == NULL ){
            depth = 0;
            return true;
        }
        int dl = 0, dr = 0;
        if( !helper(node->left, dl) ||
            !helper(node->right,dr) ||
            abs(dl-dr)>1
        ) return false;
        depth = (dl>dr?dl+1:dr+1); // err #2: ... and dot forget to return it
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if( root == NULL ) return true;
        int dl = 0, dr = 0;
        if( !helper(root->left, dl) ||
            !helper(root->right,dr) ||
            abs(dl-dr)>1
        ) return false;
        return true;
    }
};
