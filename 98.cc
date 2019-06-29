class Solution {
public:
    bool bst(TreeNode *node, int &max, int &min){
        if( node == NULL ) return true;
        int min_left  = node->val, max_left  = node->val;
        int min_right = node->val, max_right = node->val;
        if( bst(node->left,  max_left,  min_left) &&
            bst(node->right, max_right, min_right ) )
            if( (node->left  == NULL || max_left  < node->val) &&
                (node->right == NULL || min_right > node->val) ){
                min = min_left;
                max = max_right;
                return true;
            }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        // BST: all on the left are smaller, on the right are bigger:
        // maintain max in left and min in right subtree (or both)
        int min, max;
        return bst(root,max,min);
    }
};
