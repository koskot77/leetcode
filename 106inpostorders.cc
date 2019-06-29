// In-order:   call_left, element, call_right
// Post-order: call_left, call_right, element

class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& post, int from, int to) {
        if( from >= to || post < 0 ) return NULL;
        int cur = postorder[post--];

        TreeNode *node = new TreeNode(cur);
        int pos = 0;
        for(pos=from; pos<to; ++pos) if( inorder[pos] == cur ) break;

        node->right = helper(inorder,postorder,post,pos+1,to);
        node->left  = helper(inorder,postorder,post,from,pos);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post = postorder.size()-1;
        return helper(inorder,postorder, post, 0, inorder.size());
    }
};
