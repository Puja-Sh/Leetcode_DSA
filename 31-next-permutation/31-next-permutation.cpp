class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int p1=-1, p2=-1;
        
        // Traversing from the back
        for(int i=n-1; i>=0; i--) {
            if(nums[i] < nums[i+1]){
                p1=i;
                break;
            }
        }
        
        // If the given permut. is last then return the first permut. which will be the sorted form of vectors
        if(p1 == -1) return sort(nums.begin(), nums.end());
        
        // Finding index from the back where value is greater than the value of at index p1
        for(int i=n; i>=0; i--){
            if(nums[i] > nums[p1]){
                p2 = i;
                break;
            }
        }
        
        // Swap p1 and p2
        swap(nums[p1],nums[p2]);
        
        // Reverse elements after p1 point
        reverse(nums.begin()+p1+1, nums.end());
        
    }
};