class Solution {
public:
    // Approching it from the end, where if k > 25 means last character should be 'z'
    // Till when I'll get a particular character(let ch) which will make sum k
    // a + a + a + ....ch.... + z + z
    // So here, will find the ch which will make the sum = k
    
    string getSmallestString(int n, int k) {
        string ans(n,'a');     // string of size n where all char are 'a'
        
        k = k - n;      // as all 'a' will have value 1 i.e if n=5 then left k=n-(sum of all a);
        
        while(k>0){
            ans[--n] += min(25, k);
            k = k - min(25, k);
        }
        
        return ans;
        
    }
};