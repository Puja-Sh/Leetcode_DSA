class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prev_sum=0;
        int ans_max = INT_MIN;
        
        for(int i=0; i<n; i++){
            prev_sum = max(nums[i], nums[i] + prev_sum);
            ans_max = max(ans_max, prev_sum);
        }
        
        return ans_max;
    }
};