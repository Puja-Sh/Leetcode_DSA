```
vector<int> rearrangeArray(vector<int>& nums) {
int n = nums.size();
vector<int> pos, neg;
for(int i=0; i<n; i++){
if(nums[i] < 0) neg.push_back(nums[i]);
else pos.push_back(nums[i]);
}
vector<int> ans;
int j=0;
int size = pos.size();
while(j < size){
ans.push_back(pos[j]);
ans.push_back(neg[j]);
j++;
}
return ans;
}
```