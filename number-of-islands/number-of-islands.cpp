class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        int island = 0;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    visitedIsland(grid, i, j,row, col);
                    island++;
                    
                }
            }
        }
        return island;
    }
    
    
    void visitedIsland(vector<vector<char>>& grid, int x, int y, int r, int c) {
        if(x<0 || y<0 ||  x>=r || y>=c || grid[x][y] != '1' ) return;
        
        grid[x][y] = '2';
        
        visitedIsland(grid, x-1, y, r, c); //TOP
        visitedIsland(grid, x, y-1, r, c); //LEFT
        visitedIsland(grid, x+1, y, r, c); //DOWN
        visitedIsland(grid, x, y+1, r, c); //RIGHT
    }
};