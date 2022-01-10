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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> el;
        
        inOrder(root,k,el);
        return el[k-1];
    }
    
    void inOrder(TreeNode* root, int k, vector<int>& el){
        if(root == NULL) return;
        
        inOrder(root->left, k, el);
        
        if(el.size() > k) return;
        
        el.push_back(root->val);
        inOrder(root->right, k, el);
    }
};