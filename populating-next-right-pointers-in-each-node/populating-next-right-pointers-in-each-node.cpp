/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // t = temp node (watch pepcoding video for explanation)
    
    Node* connect(Node* root) {
        Node* pointer = root;
        
        while(pointer != NULL && pointer->left != NULL){
            Node *t = pointer;
            
            while(true){
                t->left->next = t->right;   // node -> left -> next ==== node ->right
                
                if(t->next == NULL) break;  // if node reached to last right node
                
                t->right->next = t->next->left; // node -> right -> next ==== node -> next -> left
                t = t -> next;
            }
            pointer = pointer -> left; // All will start from most left node only
        }
        
        return root;
    }
};