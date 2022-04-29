​
Map solution
TC-O(n2)
​
```
int lengthOfLongestSubstring(string s) {
if(s.length() == 0 ) return 0;
map<char, int> m;
int result=INT_MIN;
​
int l=0, r=0;
while(r<s.length()){
if(m.find(s[r]) != m.end()){
l++;
r=l;
m.clear();
}
m[s[r]] = 1;
result = max(result, r-l+1);
r++;
}