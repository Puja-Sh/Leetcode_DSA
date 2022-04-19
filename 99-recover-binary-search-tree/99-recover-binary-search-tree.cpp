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
    // Three function 
    // 1. recoverTree - main func 
    // 2. inorderTraver - inorder traversing to get ascending order
    // 3. SwappingNode - to find the exactly two node which need swapping
    // 4. CorrectingTree - to correct the tree by using swapping node
    
    void inorderTraverse(TreeNode* root, vector<int>& v) {
        if(root == NULL) return;
        
        inorderTraverse(root->left, v);
        v.push_back(root->val);
        inorderTraverse(root->right, v);
    }
    
    void correctingTree(TreeNode* r, int count, int x, int y){
        if(r != NULL) {
            if(r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) return;
            }
            
            correctingTree(r->left, count, x, y);
            correctingTree(r->right, count, x, y);
        }
    }
        
    int* swappingNode(vector<int> v){
        int* arr = new int[2];
        int x=INT_MIN, y=INT_MIN;
        for(int i=0; i<v.size()-1; i++){
            if(v[i+1] < v[i]){
                y = v[i+1];
                if(x == INT_MIN) {
                    x=v[i];
                } else {
                    break;
                }               
            }
        }
        arr[0] = x;
        arr[1] = y;
        return arr;
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorderTraverse(root, v);
        int* swap = swappingNode(v);
        
        correctingTree(root, 2, swap[0], swap[1]);
    }
};