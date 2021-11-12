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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        stack<vector<int>> s;   // for LIFO
        
        vector<int> temp;
        
        int size = q.size();
       
        
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
            if(--size == 0){
                s.push(temp);
                temp.clear();
                size = q.size();
            }            
        } 
    
        while(!s.empty()){
            vector<int> temp = s.top();
            res.push_back(temp);
            s.pop();
        }
        
        return res;
    }   
};