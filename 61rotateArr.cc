/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL ) return head;
        ListNode *cur = head, *lag_k = head;
        int nElem = 1;
        while( cur->next != NULL ) { ++nElem; cur = cur->next; }
        cur = head; // err #1: forgot to re-initialize
        k = k % nElem;
        for(int i=k; cur->next != NULL ; cur = cur->next, --i)
            if( i<=0 ) lag_k = lag_k->next;
        cur->next = head;
        ListNode *ret = lag_k->next;
        lag_k->next = NULL;
        return ret;
    }
};
