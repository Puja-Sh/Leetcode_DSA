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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        } else if(isMatching(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
    
    bool isMatching(TreeNode* r, TreeNode* sr){
        if(r == NULL || sr == NULL){
            return r==NULL && sr==NULL;
        } else if(r->val == sr->val){
            return isMatching(r->left, sr->left) && isMatching(r->right, sr->right);
        } else {
            return false;
        }
    }
};