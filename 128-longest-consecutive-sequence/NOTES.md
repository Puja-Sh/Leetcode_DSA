TC- O(nlogn)
```
class Solution {
public:
int longestConsecutive(vector<int>& nums) {
int n = nums.size();
if(n == 0) return 0;
sort(nums.begin(), nums.end());
int count=0, ans=INT_MIN;
for(int i=1; i<n; i++){
if(nums[i] == nums[i-1]+1){
count++;
} else if(nums[i] == nums[i-1]){
continue;
} else {
count=0;
}
ans = max(ans, count);
}
return ans == INT_MIN? 1 : ans+1;
}
};
```