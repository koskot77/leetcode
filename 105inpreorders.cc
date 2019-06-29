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
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int& pre, int from, int to)
    {
        if( from >= to ) return NULL;
        int cur = preorder[pre++], pos;
        if( from+1 == to ) return new TreeNode(cur);

        for(pos=from; pos<to; ++pos)
            if( inorder[pos] == cur ) break;

        TreeNode *node = new TreeNode(cur);
        node->left  = helper(preorder,inorder,pre, from, pos);
        node->right = helper(preorder,inorder,pre, pos+1, to);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0;
        return helper(preorder, inorder, pre, 0, inorder.size());
    }
};
