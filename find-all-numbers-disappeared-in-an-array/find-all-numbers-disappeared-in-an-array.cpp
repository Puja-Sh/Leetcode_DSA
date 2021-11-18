class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n= nums.size(), maxEl=INT_MIN;
        vector<int> ans;
        map<int,int> m;
        
        for(int i=0; i<n; i++){
            m[nums[i]] = 1;
        }
        
        for(int i=1; i<=n;i++){
            if(m.find(i) == m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};