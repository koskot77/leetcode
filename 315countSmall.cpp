#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:

    // BST node:
    struct node {
        int key;
        int nLeftSubtree;   // number of elements in the left subtree
        int nSmallerAbove;  // number of elements in all higher order subtrees to the left of this node
        node *parent;
        node *left;
        node *right;
        node(int k):key(k),nLeftSubtree(0),nSmallerAbove(0),parent(0),left(0),right(0){}
    };

    // customized BST insert implementation:
    node* insert(node *root, int key){
        node *cur = root;
        while( 1 ){
            // push the key down to left or right subtrees of the current node
            if( cur->key < key ){ // bigger key goes to the right
                if( cur->right ){ // right child's place is taken
                    // update right child's counter for 
                    cur->right->nSmallerAbove = cur->nSmallerAbove + 1 + cur->nLeftSubtree;
                    // move on to the right child
                    cur = cur->right;
                } else { // right child's place is vacant, attach a new leaf node
                    cur->right = new node(key);
                    cur->right->parent = cur;
                    // remember number of elements in all higher-order subtrees to the left
                    cur->right->nSmallerAbove = cur->nSmallerAbove + 1 + cur->nLeftSubtree;
                    return cur->right;
                }
            } else {
                // smaller key goes to the left subtree
                cur->nLeftSubtree++;
                if( cur->left ){
                    // the node to the left has same number of elements from higher-order left subtrees as parent, just update it
                    cur->left->nSmallerAbove = cur->nSmallerAbove;
                    // move on to the left child
                    cur = cur->left;
                } else { // left child's place is vacant, attach a new leaf node
                    cur->left = new node(key);
                    cur->left->parent = cur;
                    // no change to the rest of the tree -> the number of elements propagates down as is
                    cur->left->nSmallerAbove = cur->nSmallerAbove;
                    return cur->left;
                }
            }
        }
    }
/*
int traverse(node *root){
    if( !root ) return 0;

    int nLeft  = traverse(root->left);
    root->nSmaller = nLeft;
    if( root->parent ){
        if( root->parent->right == root )
            root->nSmaller += root->parent->nSmaller + 1;
    }
    int nRight = traverse(root->right);

    return nLeft + 1 + nRight;
}
*/
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts( nums.size(), 0 );

        if( nums.size() == 0 ) return counts;

        vector<node*> bst( nums.size(), 0 );

        vector<int>::const_reverse_iterator n = nums.rbegin();
        node *root = new node( *n++ );
        bst[ nums.size()-1 ] = root;

        for(int pos = nums.size()-2; n != nums.rend(); n++,pos--){
            node *nn = insert(root,*n);
            counts[pos] = nn->nSmallerAbove;
        }

//        for(int pos = nums.size()-2; n != nums.rend(); n++,pos--){
//            node *nn = insert(root,*n);
//            bst[ pos ] = nn;
//        }
//
//        traverse(root);

//        for(int pos=0; pos<nums.size(); pos++)
//            counts[pos] = bst[pos]->nSmaller;

        return counts;
    }
//};

int main(void){

    vector<int> nums;

    nums.push_back(13);
    nums.push_back(2);
    nums.push_back(97);
    nums.push_back(3);
    nums.push_back(76);
    nums.push_back(99);
    nums.push_back(51);
    nums.push_back(9);
    nums.push_back(21);
    nums.push_back(84);
    nums.push_back(66);
    nums.push_back(65);
    nums.push_back(36);
    nums.push_back(100);
    nums.push_back(41);


    vector<int> res = countSmaller(nums);
    for(vector<int>::const_iterator r=res.begin(); r!=res.end(); r++)
        cout<<*r<<", ";
    cout<<endl;

/*
    node *root = new node(1);
    node *cl1  = new node(-20);
    node *cr1  = new node(20);
    cl1->parent = root;
    cr1->parent = root;
    root->left  = cl1;
    root->right = cr1;

    node *cl2  = new node(10);
    node *cr2  = new node(30);
    cl2->parent = cr1;
    cr2->parent = cr1;
    cr1->left  = cl2;
    cr1->right = cr2;

    node *cl3  = new node(-30);
    node *cr3  = new node(-10);
    cl3->parent = cl1;
    cr3->parent = cl1;
    cl1->left  = cl3;
    cl1->right = cr3;

    node *res = predecessor(root,15);
    cout<<" res="<<res->key<<endl;
*/
    return 0;
}
