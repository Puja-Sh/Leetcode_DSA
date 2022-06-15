class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        int grow = grid.size(), gcol = grid[0].size(), msize = moveCost.size();
        
        vector<vector<int>> cost(grow, vector<int> (gcol, 0));
    
        for(int i=0; i<gcol; i++){
            cost[0][i] = grid[0][i];
        }
        
        for(int i=1; i<grow; i++){
            for(int j=0; j<gcol; j++){
                
                int costFromPrevRow = INT_MAX;
                
                for(int k=0; k<gcol; k++){
                    costFromPrevRow = min(costFromPrevRow, cost[i-1][k] + moveCost[grid[i-1][k]][j] );
                }
                
                cost[i][j] = costFromPrevRow + grid[i][j];
            }
        }
    
        int minInLastRow = INT_MAX;
    
        for(int i:cost[grow-1]){
            minInLastRow = min(minInLastRow, i);
        }
        
        return minInLastRow;
    }
};