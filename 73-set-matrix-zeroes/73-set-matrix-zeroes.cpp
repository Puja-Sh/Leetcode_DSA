class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<pair<int,int>> zeroesIndex;
        
        for(int i=0; i<row ; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    zeroesIndex.push_back(make_pair(i,j));
                }
            }
        }
       
        // zeroesIndex = (0,0), (0,3) --> example 2
        
        for(int i=0; i<zeroesIndex.size(); i++) {
            helper(zeroesIndex[i].first , zeroesIndex[i].second, matrix);
        }
    }
    
    void helper(int x, int y, vector<vector<int>>& matrix) {        
        for(int i=0; i<matrix[0].size(); i++) {
            matrix[x][i] = 0;
        }
        for(int i=0; i<matrix.size(); i++){
            matrix[i][y] = 0;
        }
    }
};