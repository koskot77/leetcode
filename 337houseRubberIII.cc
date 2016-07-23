#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<TreeNode*,int> rootIncluded;
map<TreeNode*,int> rootNotIncluded;

int max(int a, int b){
    if( a>b ) return a;
    else      return b;
}

void traverse(TreeNode *node){

    if( node->left == NULL && node->right == NULL ){
        rootIncluded   [node] = node->val;
        rootNotIncluded[node] = 0;
        return;
    }

    if( node->left == NULL && node->right != NULL ){
        traverse(node->right);
        rootIncluded   [node] = rootNotIncluded[node->right] + node->val;
        rootNotIncluded[node] = max(rootIncluded[node->right],rootNotIncluded[node->right]);
        return;
    }

    if( node->left != NULL && node->right == NULL ){
        traverse(node->left);
        rootIncluded   [node] = rootNotIncluded[node->left] + node->val;
        rootNotIncluded[node] = max(rootIncluded[node->left],rootNotIncluded[node->left]);
        return;
    }

    traverse(node->left);
    traverse(node->right);
    rootIncluded   [node] = rootNotIncluded[node->right] + rootNotIncluded[node->left] + node->val;
    int a = rootIncluded[node->right] + rootIncluded[node->left];
    int b = rootNotIncluded[node->right] + rootIncluded[node->left];
    int c = rootIncluded[node->right] + rootNotIncluded[node->left];
    int d = rootNotIncluded[node->right] + rootNotIncluded[node->left];

    rootNotIncluded[node] = max(a,max(b,max(c,d)));
}

int main(void){
    TreeNode *root;

    // [4,1,null,2,null,3]
    root = new TreeNode(4);
    root->right = NULL;
    TreeNode *n1 = new TreeNode(1);
    root->left  = n1;
    n1->right = NULL;
    TreeNode *n2 = new TreeNode(2);
    n1->left = n2;
    n2->right = NULL;
    TreeNode *n3 = new TreeNode(3);
    n2->left = n3;
    n3->left = NULL;
    n3->right = NULL;

    traverse(root);
    if( root == NULL ) return 0;

    traverse(root);
    int result = 0;

    if( rootIncluded[root] > rootNotIncluded[root] )
        result = rootIncluded   [root];
    else
        result = rootNotIncluded[root];

    printf("%d\n",result);

    return 0;
}
