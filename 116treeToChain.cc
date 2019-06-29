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
    void traverse(Node *node, int level, vector<vector<Node*>>& level_chain){
        if( node == NULL ) return;
        if( level_chain.size() == level )
            level_chain.push_back(vector<Node*>());
        traverse(node->left,  level+1, level_chain);
        traverse(node->right, level+1, level_chain);
        level_chain[level].push_back(node);
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> level_chain;
        int l = 0;
        traverse(root,l,level_chain);
        for(auto &level: level_chain)
            for(int i=0; i<level.size()-1; ++i)
                level[i]->next = level[i+1];
         return root;
    }
};

// err tried overcomplicate an obvious task

// #117 old:
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void traverse(TreeLinkNode *root, int level, TreeLinkNode *last[100])
    {
        if( root == NULL ) return;
        traverse(root->left, level+1, last);
        if( last[level] ) last[level]->next = root;
        last[level] = root;
        traverse(root->right, level+1, last);

    }
    void connect(TreeLinkNode *root) {
        TreeLinkNode *last[100];
        bzero(last,sizeof(TreeLinkNode)*100);
        traverse(root,0,last);
    }
};
