class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        
        int left=0, right=n-1, top=0, bottom=n-1;
        
        int total = n*n;
        int count = 0;
        int el = 1;
        
        while(count<total){
            
            for(int i=left; i<=right; i++){
                matrix[top][i] = el;
                el++;
                count++;
            }
            top++;
            
            for(int i=top; i<=bottom; i++){
                matrix[i][right]=el;
                el++;
                count++;
            }
            right--;
            
            for(int i=right; i>=left; i--){
                matrix[bottom][i] = el;
                el++;
                count++;
            }
            bottom--;
            
            for(int i=bottom; i>=top; i--){
                matrix[i][left]=el;
                el++;
                count++;
            }
            left++;
            
        }
        
        return matrix;
    }
};