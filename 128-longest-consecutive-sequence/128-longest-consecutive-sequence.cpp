class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        
        set<int> nums_set(nums.begin(), nums.end());
        
        int count = 1, ans = INT_MIN;
        
        for(int el : nums_set){
            int curr = el;
            if(nums_set.find(curr+1) != nums_set.end()){
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }
        
        return ans;
    }
};