class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        int res=0, freq=INT_MIN;
        for(auto x:m){
            if(x.second > freq){
                res = x.first;
                freq = x.second;
            }
        }
        return res;
    }
};