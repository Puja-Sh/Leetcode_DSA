class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int res = INT_MIN;
        
        for(int i=1; i<n; i++){
            int sum = nums[i] + dp[i-1];
            
            if(sum > nums[i]){          // if sum is greater, then take the sum otherwise take the number itself
                dp[i] = sum;
            } else {
                dp[i] = nums[i];
            }
        }
        
        for(int i=0; i<n; i++){
            res = max(res, dp[i]);
        }
        
        if(res == INT_MIN){
            return nums[0];
        } else {
            return res;
        }
       
    }
};