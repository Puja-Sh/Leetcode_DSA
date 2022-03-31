class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxi = 0, sum = 0;
        
        for(int val: nums) {
            sum+= val;
            maxi = max(maxi, val);
        }
        
        if(m == nums.size()) return maxi;
        
        int low=maxi, high=sum, ans=0;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(helperPossible(nums, mid, m)){
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            } 
        }
        
        return ans;
    }
    
     bool helperPossible(vector<int>& nums, int mid, int m){
         int sub = 1;
         int sum = 0;
         
         for(int i=0; i<nums.size(); i++){
             sum+= nums[i];
             
             if(sum >  mid){
                 sub++;
                 sum = nums[i];
             }
         }
         
         return sub <= m;
     }
};