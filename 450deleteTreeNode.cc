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
//         50
//       /     \
//      3
//    /   \
//  2       5
// / \     / \
//1   2.5 4   6
//         \
//         4.5
// idea: bubble down the removed node until it is a leaf - no search tree property is violated
// swapping a leaf is easy, and the BST property is that minimal node from the right is still bigger than maximum from the left
// basd on that, let's find one of those and simply move it in the position of deleted node
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if( root == NULL ) return root;
        
        if( root->val == key ){
            if( root->left == NULL )
                return root->right;
            if( root->right == NULL )
                return root->left;
            // attach the left subtree to the smallest node of right subtree
            // place right subtree in place of this node
            TreeNode *minRight = root->right;
            while( minRight->left != NULL ) minRight = minRight->left;
            minRight->left = root->left;
            return root->right;
        }

        if( root->val > key )
            root->left  = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);

        return root;
    }
};
