#include<iostream>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};


    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL || head->next == NULL ) return head;
        ListNode *odd = head, *even = head->next, *tail = head->next;
        while( even->next != NULL ){
            odd->next = even->next;
            odd = even->next ;
            if( even->next->next != NULL ){
                ListNode *next = even->next->next;
                even->next = even->next->next;
                even = next;
            } else
                even->next = NULL;
        }
        odd->next = tail;
        

        return head;

    }

int main(void){
   ListNode *n1 = new ListNode(1);
   ListNode *n2 = new ListNode(2);
   n1->next = n2;
   ListNode *n3 = new ListNode(3);
   n2->next = n3;
   ListNode *n4 = new ListNode(4);
   n3->next = n4;
   n4->next = NULL;

   ListNode *n = oddEvenList(n1);

   cout<<"n1="<<n1<<" n2="<<n2<<" n3="<<n3<<" n4="<<n4<<endl;
   cout<<"n1n="<<n1->next<<" n2n="<<n2->next<<" n3n="<<n3->next<<" n4n="<<n4->next<<endl;


//   while( n ){ cout<<n->val<<endl; n = n->next; }

    return 0;
}
