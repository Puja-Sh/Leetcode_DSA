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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> list;
        
        if(start > end){
            list.push_back(NULL);
            return list;
        }
        
        if(start == end) {
            list.push_back(new TreeNode(start));
            return list;
        }
        
        vector<TreeNode*> left, right;
        for(int i=start; i<=end; i++) {
            left = helper(start, i-1);          // left elements of ith index
            right = helper(i+1, end);           // right elements of ith index
            
            for(auto lnode:left) {
                for(auto rnode: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};