/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* helper(ListNode *head, ListNode *till){
        if( head == till ) return NULL;
        if( head->next == till ) return new TreeNode(head->val);
        int nelem = 0;
        ListNode *lnode = head, *lnode_slow = head;
        for(; lnode != till; lnode=lnode->next)
            if( (nelem++)%2 ) lnode_slow = lnode_slow->next;
        TreeNode *node = new TreeNode(lnode_slow->val);
        node->left  = helper(head, lnode_slow); // err #1
        node->right = helper(lnode_slow->next, till); // err #2
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head,NULL);
    }
};
