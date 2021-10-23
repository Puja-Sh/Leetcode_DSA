/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        vector<Node*> visited(1000, NULL);
        Node* copy = new Node(node->val);
        
        dfs(node, copy, visited);
        return copy;
    }
    
    void dfs(Node* node, Node* copy, vector<Node*>& visited){
        visited[copy->val] = copy;
        
        for(auto x:node->neighbors){
            if(visited[x->val] == NULL) {
                Node* newNode = new Node(x->val);
                (copy->neighbors).push_back(newNode);
                dfs(x, newNode, visited);
            } else {
                (copy->neighbors).push_back(visited[x->val]);
            }
        }
    }
};