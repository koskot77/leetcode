class Solution {
public:
    string traverse(TreeNode* root, int level, bool inverse) {
        string retval;
        if( inverse ){
            if( root->right )
                retval += traverse(root->right,level+1,inverse) + ",";
            retval += to_string(root->val) + ":" + to_string(level);
            if( root->left )
                retval += "," + traverse(root->left,level+1,inverse);
        } else {
            if( root->left )
                retval += traverse(root->left,level+1,inverse) + ",";
            retval += to_string(root->val) + ":" + to_string(level);
            if( root->right )
                retval += "," + traverse(root->right,level+1,inverse);
        }
        return retval;
    }

    bool isSymmetric(TreeNode* root) {
        if( root == NULL ) return true;
        if( root->left == NULL && root->right == NULL ) return true;
        if( root->left != NULL && root->right != NULL ){
            
            string left  = traverse(root->left,1,false);
            string right = traverse(root->right,1,true);
            if( left == right ) return true;
        }
        return false;
    }
};
