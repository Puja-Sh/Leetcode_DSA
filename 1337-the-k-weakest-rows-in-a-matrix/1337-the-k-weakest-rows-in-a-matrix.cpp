class Solution {
public:    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> eachRow;
        
        for(int i=0; i<mat.size(); i++){
            int soldiers = 0;
            
            for(int j=0;j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    soldiers++;
                }
            }
            eachRow.push_back(make_pair(soldiers, i));
        }
        
        sort(eachRow.begin(), eachRow.end());
        
        vector<int> result;
        int idx=0;
        
        while(k--){
            result.push_back(eachRow[idx].second);
            idx++;
        }
        
        return result;
    }
};