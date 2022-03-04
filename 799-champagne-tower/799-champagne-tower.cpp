class Solution {
public:
    // 799. Champagne Tower
    double champagneTower(int poured, int query_row, int query_glass) {
        double quantity[102][102] = {0.0};
        
        quantity[0][0] = (double)poured;
        
        int row = query_row, col = query_glass;
        
        for(int i=0; i< 100; ++i){
            for(int j=0; j<=i; ++j){
                
                if(quantity[i][j] >= 1) {
                    double rest = quantity[i][j] - 1;
                    
                    quantity[i+1][j] += rest/2.0;
                    quantity[i+1][j+1] += rest/2.0;
                    quantity[i][j] = 1;
                }
                
            }
        }
        return quantity[query_row][query_glass];
    }
};