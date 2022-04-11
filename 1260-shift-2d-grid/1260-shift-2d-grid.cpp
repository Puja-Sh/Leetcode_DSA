class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        int row = grid.size(), col = grid[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                temp.push_back(grid[i][j]);
            }
        }
        
        if(k>temp.size()){
            k = k % temp.size();
        }
        
        int tempSize = temp.size()-k;
        
        reverse(temp.begin(), temp.end());
        
        reverse(temp.begin()+k, temp.end());
               
        reverse(temp.begin(),temp.end()-tempSize);        
        int ind = 0;
        
        for(int i=0;i< row; i++){
            for(int j=0; j<col; j++){
                grid[i][j] = temp[ind];
                ind++;
            }
        }
        
        return grid;
    }
};