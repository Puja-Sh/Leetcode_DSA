class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(); 
        int zero=0,one = 0,two=0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 2) two++;
            else one++;
        }
        
        for(int i=0; i<n;i++) {
            if(zero){
                nums[i] = 0;
                zero--;
            } else if(one){
                nums[i] = 1;
                one--;
            } else if(two) {
                nums[i] = 2; two--;
            }
        }
    }
};