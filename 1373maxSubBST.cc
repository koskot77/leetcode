// error #1: you've solved it and forgot it completely
// error #2: swapped min<->max in arguments and didn't see if for the whole day!
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
    bool maxmin(TreeNode *node, int &max, int &min, int &sum, int &winner){
        if( node == NULL ) return true;
        int sum_left{}, sum_right{};
        int max_left{node->val}, max_right{node->val}, min_left{node->val}, min_right{node->val};
        bool left_bst  = maxmin(node->left,  max_left,  min_left,  sum_left,  winner);
        bool right_bst = maxmin(node->right, max_right, min_right, sum_right, winner);
        if( (node->left == NULL || (left_bst  && max_left  < node->val)) &&
            (node->right== NULL || (right_bst && node->val < min_right)) ){
            sum = sum_left + node->val + sum_right;
            max = max_right;
            min = min_left;
            if( winner < sum ) winner = sum;
            return true;
        }
        return false;
    }

    int maxSumBST(TreeNode* root) {
        int sum{}, max{}, min{}, winner{0};
        maxmin(root,max,min,sum,winner);
        return winner;
    }
};
