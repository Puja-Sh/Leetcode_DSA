class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> trustVec(n+1, make_pair(0,0));
        
        for(int i=0; i<trust.size(); i++){
                trustVec[trust[i][0]].first++;
                trustVec[trust[i][1]].second++;
        }
        
        for(int i=1; i<trustVec.size(); i++){
            if(trustVec[i].second == n-1 && trustVec[i].first == 0){
                return i;
            }
        }
        
        return -1;
    }
};