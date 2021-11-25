/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // TC: O(logN)
    // Searching a root whoes left || right value are matching with the key
    // pointing key's root->left = key->left
    // finding the most right node on left sub Tree to attach the key's right sub Tree
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        // if root->val matching with the key
        if(root->val == key) {
            return helperDelete(root);
        }
        
        TreeNode* head = root;
        
        // Binary Search in the BST
        while(root != NULL){
            if(root->val > key) {
                if(root->left!=NULL && root->left->val == key){
                    root->left = helperDelete(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if(root->right!=NULL && root->right->val == key){
                    root->right = helperDelete(root->right);
                    break;
                } else {
                    root=root->right;
                }
            }
        }
        
        return head;
    }
    
    TreeNode* helperDelete(TreeNode* root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        
        TreeNode* rightSubChild = root->right;
        TreeNode* lastRightNode = helperLastRight(root->left);
        lastRightNode->right = rightSubChild;
        
        return root->left;
    }
    
    
    TreeNode* helperLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return helperLastRight(root->right);
    }
};