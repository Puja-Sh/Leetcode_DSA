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
    // Inorder Traversal and create a new Tree
    
    void inorder(TreeNode*& ordered, TreeNode* root){
        if(!root) return;
        
        inorder(ordered, root->left);
        
        ordered->right = new TreeNode(root->val);
        ordered = ordered->right;
        
        inorder(ordered, root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* orderedHead; 
        TreeNode* ordered = new TreeNode(0);
       
        orderedHead = ordered;
        
        inorder(ordered, root);
        
        return orderedHead->right;
    }
};