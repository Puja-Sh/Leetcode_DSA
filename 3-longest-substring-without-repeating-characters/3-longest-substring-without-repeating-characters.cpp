class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l=0, r=0;
        int len=INT_MIN;
        
        if(n == 0) return 0;
        
        map<char,int> m;
        
        for(auto x:s){
            m[x] = -1;
        }
        
        while(r < n){
            
            if(m[s[r]] == -1){
                m[s[r]] = 1;
                len = max(len, r-l+1);
                r++;
            } else {
                m[s[l]] = -1;
                l++;
            }
        }
        
        return len;
    }
};