class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return helperBinarySearch(nums, 0, nums.size()-1);
    }
    
    int helperBinarySearch(vector<int>& nums, int left, int right) {
        if(left < right) {
            int mid = (left+right)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            } else if(nums[mid] == nums[mid+1]) {
                int start = left - mid;
                int end = right - mid - 1;
                if(start % 2 == 0){
                    return helperBinarySearch(nums, mid+2, right);
                }
                return helperBinarySearch(nums, left, mid-1);
            } else {
                int start = mid - left - 1;
                int end = right - mid;
                if(start % 2 == 0){
                    return helperBinarySearch(nums, mid+1, right);
                }
                return helperBinarySearch(nums, left, mid-2);
                
            }
        }
        return nums[left];
    }
};