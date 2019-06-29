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
    int max_path(TreeNode *node, int& sum){
        // sum_l and sum_r is the best path found somewhere in right and left subtrees
        // cand - is best path including the current node
        // return value - best single leg from the current node
        if( node == NULL ) return 0;
        int sum_l = 0, sum_r = 0;
        int left  = max_path(node->left,  sum_l);
        int right = max_path(node->right, sum_r);
        int cand = (left>0?left:0) + node->val + (right>0?right:0);
        if( node->left && node->right )
            sum = max(cand,max(sum_l,sum_r));
        else if( node->left ) sum = max(cand, sum_l);
        else if( node->right) sum = max(cand, sum_r);
        else sum = cand;
        int best_leg = max(left,right);
        return (best_leg > 0 ? best_leg : 0) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        // path from node to node is either descending,
        // or climbs up to a certain "local root"
        // in which case it is a sum of two descending paths
        // Run down the tree and look for best path
        int retval = 0;
        max_path(root,retval);
        return retval;
    }
};

// err: tried to overcomplicate again
