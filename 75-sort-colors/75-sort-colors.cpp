class Solution {
public:
    void sortColors(vector<int>& nums) {
       int l = 0, equal = 0, h = nums.size()-1;
        
        while(equal <= h){
            
            if(nums[equal] == 0) swap(nums[l++], nums[equal++]);
            else if(nums[equal] == 1) equal++;
            else swap(nums[h--], nums[equal]);
            
        }
    }
};