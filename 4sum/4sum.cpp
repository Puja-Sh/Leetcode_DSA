class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                // a+b+c+d = target
                // c+d = target - a-b
                int target_2 = target - nums[i] - nums[j];
                
                int left = j+1, right = n-1;
                
                while(left < right) {
                    // twoSum = x+y
                    // for checking x+y == target_2 (c+d) ? 
                    int twoSum = nums[left] + nums[right];
                    
                    if(twoSum < target_2) {
                        left++;
                    } else if(twoSum > target_2){
                        right--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        
                        left++; right--;
                    }
                }
                // Processing the duplication for jth position
                while(j+1 < n && nums[j] == nums[j+1]) ++j;
            }
            // Processing the duplication for ith position
            while(i+1 < n && nums[i] == nums[i+1]) ++i;
        }
        return ans;
    }
};