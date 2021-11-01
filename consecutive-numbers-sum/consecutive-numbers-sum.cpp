class Solution {
public:
    // TC:  O(sqrt N)
    int consecutiveNumbersSum(int n) {
        int count = 0;
        
        // x > 0 --> N/k - (k + 1)/2 > 0
        int upper = sqrt(2*n + 0.25) - 0.5;
        
        for(int k=1; k<=upper; ++k){
            // x should be an integer
            if((n-k * (k+1) / 2) % k == 0){
                count++;
            }
        }
        return count;
    }
};