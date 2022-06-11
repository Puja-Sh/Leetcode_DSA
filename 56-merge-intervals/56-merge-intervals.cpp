class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(intervals.begin(), intervals.end());
        
        temp = intervals[0];    // consider the first element as a answer
        
        for(auto it : intervals){
            if(temp[1] >= it[0]){    // merging condition: [temp0, temp1], [it[0], it[1], ....]
                temp[1] = max(it[1], temp[1]);
            } else {
                ans.push_back(temp);
                temp = it;
            }
        }
        
        ans.push_back(temp);
        
        return ans;
    }
};