#include<iostream>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur = NULL, *begin = NULL, *prev = NULL;
        int inMind = 0;
        while( l1!=NULL || l2!=NULL ){
            int val1 = (l1!=NULL?l1->val:0);
            int val2 = (l2!=NULL?l2->val:0);
            cur = new ListNode( val1 + val2 + inMind );
            if( cur->val >= 10 ){ cur->val -= 10; inMind=1; } else { inMind=0; }
            if( begin == NULL ) begin = cur;
            if( prev  != NULL ) prev->next = cur;
            prev = cur;
            l1 = (l1!=NULL?l1->next:NULL);
            l2 = (l2!=NULL?l2->next:NULL);
        }
        if( inMind ){
            cur = new ListNode( 1 );
            prev->next = cur;
        }
        return begin;
    }
};

int main(void){
    // [2,4,3,2,3,5,7,2,4,5,7,9]
    // [5,6,4,2,1,4,4,3,5]
    ListNode *l1_1 = new ListNode(2);
    ListNode *l1_2 = new ListNode(4);
    l1_1->next = l1_2;
    ListNode *l1_3 = new ListNode(3);
    l1_2->next = l1_3;
    ListNode *l1_4 = new ListNode(2);
    l1_3->next = l1_4;
    ListNode *l1_5 = new ListNode(3);
    l1_4->next = l1_5;
    ListNode *l1_6 = new ListNode(5);
    l1_5->next = l1_6;
    ListNode *l1_7 = new ListNode(7);
    l1_6->next = l1_7;
    ListNode *l1_8 = new ListNode(2);
    l1_7->next = l1_8;
    ListNode *l1_9 = new ListNode(4);
    l1_8->next = l1_9;
    ListNode *l1_10 = new ListNode(5);
    l1_9->next = l1_10;
    ListNode *l1_11 = new ListNode(7);
    l1_10->next = l1_11;
    ListNode *l1_12 = new ListNode(9);
    l1_11->next = l1_12;

    ListNode *l2_1 = new ListNode(5);
    ListNode *l2_2 = new ListNode(6);
    l2_1->next = l2_2;
    ListNode *l2_3 = new ListNode(4);
    l2_2->next = l2_3;
    ListNode *l2_4 = new ListNode(2);
    l2_3->next = l2_4;
    ListNode *l2_5 = new ListNode(1);
    l2_4->next = l2_5;
    ListNode *l2_6 = new ListNode(4);
    l2_5->next = l2_6;
    ListNode *l2_7 = new ListNode(4);
    l2_6->next = l2_7;
    ListNode *l2_8 = new ListNode(3);
    l2_7->next = l2_8;
    ListNode *l2_9 = new ListNode(5);
    l2_8->next = l2_9;
 
    Solution s;
    s.addTwoNumbers(l1_1,l2_1);
    return 0;
}
