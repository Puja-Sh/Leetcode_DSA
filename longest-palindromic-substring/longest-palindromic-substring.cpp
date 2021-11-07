class Solution {
public:
    // We have to fill table previously for substring of length = 1 and length =2 because 
    // as we are finding , if table[i+1][j-1] is true or false , so in case of 
    // (i) length == 1 , lets say i=2 , j=2 and i+1,j-1 doesn’t lies between [i , j] 
    // (ii) length == 2 ,lets say i=2 , j=3 and i+1,j-1 again doesn’t lies between [i , j]
    
    string longestPalindrome(string s) {
        int n = s.size();
        
        int maxLength = 1;
        bool dp[n][n];
        int start = 0;
        
        memset(dp, 0, sizeof(dp));
        
        // for length = 1 ----> 0,0 | 1,1 | 2,2 .. all diagonal will be 1
        for(int i=0; i<n; ++i){
            dp[i][i] = true;
        }

        // for length = 2 ---->
        for(int i=0; i<n-1; ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        
        // for length > 2 ----->
        for(int k=3; k<=n ; ++k){
            for(int i=0; i< n-k+1; ++i){
                int j=i+k-1;
                
                if(dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    
                    if( k > maxLength){
                        maxLength = k;
                        start = i;
                    }
                }
            }
        }
        
        string ans="";
        for(int i=start; i<=start+maxLength-1; ++i){
            ans = ans+s[i];
        }
        return ans;
    }
};