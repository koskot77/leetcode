/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* dfs(Node *node, unordered_map<Node*,Node*>& explored){
        unordered_map<Node*,Node*>::iterator n = explored.find(node);
        if( n != explored.end() ){
            return n->second;
        }
        Node *new_node = new Node(node->val,vector<Node*>());
        explored[node] = new_node;
        
        for(int i=0; i<node->neighbors.size(); ++i){
            Node *new_neighbor = dfs(node->neighbors[i],explored);
            new_node->neighbors.push_back(new_neighbor);
        }
        return new_node;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> explored;
        return dfs(node,explored);
    }
};
