class Solution {
public:
    // Backtracking 
    
    int ans=INT_MAX;
    
    void helper(vector<int>& cookies, vector<int>& kv, int idx){
        
        if(idx >= cookies.size()){
            int temp = INT_MIN;
            for(int it:kv){
                temp = max(temp, it);
            }
            
            ans = min(ans, temp);
            
            return;
        }
        
        for(int i=0; i<kv.size(); i++){
            kv[i] += cookies[idx];
            
            helper(cookies, kv, idx+1);
            
            kv[i] -= cookies[idx];
        }
        
        return;
    }
    
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
       
        vector<int> kv(k, 0);
        
        helper(cookies, kv, 0);
        
        return ans;
    }
};