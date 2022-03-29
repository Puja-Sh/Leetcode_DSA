class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(auto &i : nums){
            if(seen.count(i)) return i;
            seen.insert(i);
        }
        
        return -1;
    }
};