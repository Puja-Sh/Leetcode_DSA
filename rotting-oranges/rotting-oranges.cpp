class Solution {
public:   
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int totalOrg = 0, orgCount = 0, min = 0;
        queue<pair<int,int>> rotten;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) {
                    rotten.push({i,j});
                }
                if(grid[i][j] != 0) {
                    totalOrg++;
                }
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!rotten.empty()) {
            int k = rotten.size();
            orgCount+=k;
            while(k--) {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i=0; i<4; i++) {
                    int X = x + dx[i], Y = y + dy[i];
                    
                    if(X<0 || Y<0 || X>= r || Y>=c || grid[X][Y] != 1) continue;
                    
                    grid[X][Y] = 2;
                    rotten.push({X,Y});
                }
            }
            if(!rotten.empty()) min++;
        }
        
        return orgCount == totalOrg ? min : -1;
    }  
};