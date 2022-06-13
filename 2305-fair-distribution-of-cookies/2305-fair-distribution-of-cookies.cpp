// class Solution {
// public:
//     // Backtracking 
    
//     int ans=INT_MAX;
    
//     void helper(vector<int>& cookies, vector<int>& kv, int idx){
        
//         if(idx >= cookies.size()){
//             int temp = INT_MIN;
//             for(int it:kv){
//                 temp = max(temp, it);
//             }
            
//             ans = min(ans, temp);
            
//             return;
//         }
        
//         for(int i=0; i<kv.size(); i++){
//             kv[i] += cookies[idx];      // add cookies at idx
            
//             helper(cookies, kv, idx+1); // call for next index cookies
            
//             kv[i] -= cookies[idx];  // on backtracking subtract the present index of cookies
//         }
        
//         return;
//     }
    
    
    
//     int distributeCookies(vector<int>& cookies, int k) {
//         int n = cookies.size();
       
//         vector<int> kv(k, 0);
        
//         helper(cookies, kv, 0);
        
//         return ans;
//     }
// };

class Solution {
public:
    int ans = INT_MAX;
    void solve(int idx, vector<int>& cookies, vector<int>& subset){
        
        if(idx==cookies.size()){
            int maxm = INT_MIN;
            for(int i=0;i<subset.size();i++){
                maxm = max(maxm,subset[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        
        for(int i=0;i<subset.size();i++){
            subset[i] += cookies[idx];
            solve(idx+1, cookies, subset);
            subset[i]-= cookies[idx];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> subset(k,0); 
        solve(0,cookies, subset);
        return ans;
    }
};