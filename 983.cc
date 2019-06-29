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
    string smallestFromLeaf(TreeNode* root) {
        const char lut[] =
            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
             'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
             'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
             'y', 'z'};
        if( root->left != NULL && root->right != NULL )
        {
            if( root->left->val == root->right->val )
            {
                string s1 = smallestFromLeaf( root->left );
                string s2 = smallestFromLeaf( root->right );
                if( s1 < s2 ) return lut[root->val] + s1;
                return lut[root->val] + s2;
            }
            if( root->left->val < root->right->val )
                return lut[root->val] + smallestFromLeaf(root->left);
            return lut[root->val] + smallestFromLeaf(root->right);
        }
        if( root->left != NULL )
            return lut[root->val] + smallestFromLeaf(root->left);
        if( root->right != NULL )
            return lut[root->val] + smallestFromLeaf(root->right);
        return string() + lut[root->val];
    }
};

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
    string smallestFromLeaf(TreeNode* root) {
        const char lut[] =
            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
             'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
             'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
             'y', 'z'};
        if( root->left != NULL && root->right != NULL )
        {
            string s1 = smallestFromLeaf( root->left );
            string s2 = smallestFromLeaf( root->right );
            if( s1 < s2 ) return s1 + lut[root->val];
            return s2 + lut[root->val];
        }
        if( root->left != NULL )
            return smallestFromLeaf(root->left) + lut[root->val];
        if( root->right != NULL )
            return smallestFromLeaf(root->right) + lut[root->val];
        return string() + lut[root->val];
    }
};
