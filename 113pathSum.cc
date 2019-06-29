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
    void helper(const TreeNode *root, vector<vector<int>>& paths, int sum){
        // leaf:
        if( root->left == NULL && root->right == NULL ){
            if( root->val == sum )
                paths.push_back( vector<int>({root->val}) );
            return;
        }
        vector<vector<int>> left_paths;
        if( root->left != NULL )
            helper(root->left, left_paths, sum-root->val); // accuracy error: root->left -> root
        
        vector<vector<int>> right_paths;
        if( root->right != NULL )
            helper(root->right, right_paths, sum-root->val);

        for(auto it=left_paths.begin(); it!=left_paths.end(); ++it)
            it->push_back(root->val); // error: too early to reverse
        for(auto it=right_paths.begin(); it!=right_paths.end(); ++it)
            it->push_back(root->val);

        copy(left_paths.begin(),left_paths.end(),back_inserter(paths));
        copy(right_paths.begin(),right_paths.end(),back_inserter(paths));
        //for(const auto &a : left_paths) paths.push_back(a);
        //for(const auto &a : right_paths) paths.push_back(a);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> retval;
        if( root != NULL ) helper(root,retval,sum);
        for(auto it=retval.begin(); it!=retval.end(); ++it)
            reverse(it->begin(),it->end());
        return retval;
    }
};

// numerous errors: accuracy
