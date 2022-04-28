class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int numsSum=0, sum=0;
        
        for(int i=0; i<=n; i++){
            if(i < n){
                numsSum+=nums[i];
            }
            
            sum+=i;
        }
        
        return sum-numsSum;
        
    }
};