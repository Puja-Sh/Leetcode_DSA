class Solution {
public:
    int removePalindromeSub(string s) {
        int l=0, r=s.length()-1;
        int ans = 1;
        
        while(l<r){
           if(s[l] == s[r]) {
               l++;
               r--;
           } else {
               ans++;
               return ans;
           }
        }
        
        return ans;
    }
};