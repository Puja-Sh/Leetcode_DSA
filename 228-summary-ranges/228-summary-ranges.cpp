class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if(nums.size() < 0) return result;
        
        for(int i=0; i<nums.size();){
            int start = i, end = i;
            
            while (end + 1 < nums.size() && nums[end+1] == nums[end] + 1) end++;

            if(end > start) {
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            } else {
                result.push_back(to_string(nums[start]));
            }
            
            i = end+1;
        }
        
        return result;
    }
};