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
    // BFS Method
    vector<vector<int>> verticalTraversal(TreeNode* root) {     
    vector<vector<int>> ans;        // answer
    queue<pair<TreeNode*, int>> q;  // level order traverse and store node and its y position
    q.push({root, 0});              
    map<int, vector<int>> mapTemp;  // iterate over all the nodes at same yth position
    
    while(!q.empty()){
        int size = q.size();
        map<int, multiset<int>> mapSet; //store in ascending order according to level (not by value)
        
        while(size--){
            TreeNode* curr = q.front().first;
            int y = q.front().second;
            q.pop();
            
            mapSet[y].insert(curr->val);
            
            if(curr->left != NULL){
                q.push(make_pair(curr->left, y-1));
            }
            if(curr->right != NULL){
                q.push(make_pair(curr->right, y+1));
            }
        }
        
        for(auto i:mapSet) {
            for(auto node:i.second) {
                mapTemp[i.first].push_back(node);
            }
        }
    }
    for(auto i : mapTemp) {
        ans.push_back(i.second);
    }
    return ans;
    }       
};