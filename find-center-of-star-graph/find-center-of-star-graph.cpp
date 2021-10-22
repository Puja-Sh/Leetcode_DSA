class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=INT_MIN;
        for(int i=0; i<edges.size(); i++) {
            n = max({n, edges[i][0], edges[i][1]});
        }
        
        vector<int> linked(n+1, 0);
        for(int i=0; i<edges.size(); i++){
            linked[edges[i][0]]++;
            linked[edges[i][1]]++;
        }
        int max = INT_MIN, index = -1;
        
        for(int i=1; i<linked.size(); i++){
            if(max < linked[i]){
                max = linked[i];
                index = i;
            }
        }
        
        return index;
    }
};