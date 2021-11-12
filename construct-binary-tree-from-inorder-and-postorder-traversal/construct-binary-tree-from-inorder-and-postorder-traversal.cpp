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
    // ps: postStart    pe:postEnd
    // is: inStart      ie:inEnd
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> map;
        for(int i=0; i<inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int start = 0, end = inorder.size()-1;
        int inEnd = inorder.size()-1;
        int postEnd = postorder.size()-1;
        return helper(inorder, 0, inEnd , postorder, 0, postEnd, map);
    }
    
    TreeNode* helper(vector<int>& inorder, int is, int ie , vector<int>& postorder, int ps, int pe, map<int,int>& map) {     
        
        if(ps>pe || is>ie) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int rootIndex = map[root->val];
        int remain = rootIndex - is;
        
        root->left = helper(inorder, is, rootIndex-1, postorder, ps, ps+remain-1 ,map);
        root->right = helper(inorder, rootIndex+1 , ie, postorder, ps+remain, pe-1,map);
        
        return root;
    }
};