/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:

    void traverse(Node *root, int level, Node *last[100])
    {
        if( root == NULL ) return;
        traverse(root->left, level+1, last);
        if( last[level] ) last[level]->next = root;
        last[level] = root;
        traverse(root->right, level+1, last);

    }
    Node* connect(Node* root) {
        Node *last[100];
        bzero(last,sizeof(Node*)*100);
        traverse(root,0,last);
        return root;
    }
};
