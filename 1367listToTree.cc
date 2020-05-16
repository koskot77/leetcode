// error: you cannot fit it in one function, match has to be continuous
//     bool isSubPath(ListNode* head, TreeNode* root) {
//        if( head == NULL ) return true;
//        if( root == NULL ) return false;
//        if( head->val == root->val &&
//           (isSubPath(head->next,root->left) ||
//            isSubPath(head->next,root->right)) ) return true;
//        // Discontinuity !!!
//        return isSubPath(head,root->left) || isSubPath(head,root->right);
//    }

class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if( head == NULL ) return true;
        if( root == NULL ) return false;
        if( head->val == root->val )
            return dfs(head->next,root->left) || dfs(head->next,root->right);
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if( root == NULL ) return false;
        return dfs(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};
