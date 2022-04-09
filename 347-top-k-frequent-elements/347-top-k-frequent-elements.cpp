class Solution {
public:
    typedef pair<int, int> pi;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        priority_queue<pi> pq;
        
        for(auto x:m){
            pq.push(make_pair(x.second, x.first));
        }
        
        while(!pq.empty() && k-- ){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};