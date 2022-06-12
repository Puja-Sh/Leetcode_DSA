class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
      
        int sum=0, maxSum=INT_MIN;
        int l=0;
        
        for(int i=0; i<n; i++){  
            
            if(m.find(nums[i]) != m.end()){
                int index = m[nums[i]];
                
                while(l <= index){
                    m.erase(nums[i]);
                    sum-=nums[l];
                    l++;
                }
            }
            
            m[nums[i]] = i;
            sum+=nums[i];
            
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};