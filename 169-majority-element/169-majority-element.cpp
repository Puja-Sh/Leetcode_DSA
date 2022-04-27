class Solution {
public:
    // Boyer-Moore Voting Algorithm
    // TC- O(N)
    // SC- O(1)
    
    int majorityElement(vector<int>& nums) {
        int majority=-1, count=0;
        
        for(auto x: nums){
            if(count == 0){
                majority = x;
                count++;
                continue;
            }
            
            if(x == majority){
                count++;
            }else {
                count--;
            }
        }
        
        return majority;
    }
};