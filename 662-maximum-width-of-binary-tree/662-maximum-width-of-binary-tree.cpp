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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long max_width = 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        
        q.push(make_pair(root,1));
        
        while(!q.empty()){
            unsigned long long left = q.front().second;
            unsigned long long right = left;
            int size = q.size();
            
            while(size--){
                right = q.front().second;
                TreeNode* curr = q.front().first;
                q.pop();
                
                if(curr->left) q.push(make_pair(curr->left, 2*right));
                if(curr->right) q.push(make_pair(curr->right, 2*right+1));
            }
            
            max_width = max(max_width, right-left +1);
            
        }
        
        return max_width;
    }
};