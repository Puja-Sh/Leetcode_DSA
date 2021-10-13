class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;        
        vector<vector<int>> ans;
        
        helper(0, target,candidates, v, ans);
        return ans;
    }
    
    void helper(int index, int target, vector<int> &cand, vector<int> &v, vector<vector<int>> &ans) {
   
        if(target == 0) {           // If we got the elements 
            ans.push_back(v);
            return;
        } else if(target < 0 || index >= cand.size()) {
            return;
        }
     
        v.push_back(cand[index]);
        helper(index, target - cand[index], cand, v, ans);
        v.pop_back();           // delete the last element because at that element we returend(line-18) and then 
        
        // we'll call for next index element(line-25) 
        helper(index+1, target, cand, v, ans);
        
        
        //2nd METHOD replacing v push to helper call index+1
        // for(int i=target; i<cand.size(); i++){
        //     v.push_back(cand[i]);
        //     helper(i, target-cand[i], cand, v, ans);
        //     v.pop_back();
        // }
        
    }
};
