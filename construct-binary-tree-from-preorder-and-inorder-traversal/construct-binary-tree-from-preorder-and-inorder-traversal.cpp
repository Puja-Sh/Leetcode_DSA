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
    TreeNode* building(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd,map<int,int>& mp){
        
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int rootInorder = mp[root->val];
        int steps = rootInorder - inStart;
        
        root->left = building(preorder, preStart+1, preStart+steps, inorder, inStart, rootInorder-1, mp);
        root->right = building(preorder, preStart+steps+1,preEnd, inorder, rootInorder+1, inEnd, mp );
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        
        TreeNode*root = building(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, m);
        
        return root;
        
    }
};