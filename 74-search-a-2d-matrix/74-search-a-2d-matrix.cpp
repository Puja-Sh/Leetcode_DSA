class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, col=matrix[0].size()-1;
        int row = -1;
        
        while(i < matrix.size()){
            if(target > matrix[i][0] && target < matrix[i][col]){
                row = i;
                break;
            }
            if(target == matrix[i][0] || target == matrix[i][col] ) return true;
            i++;
        }
        
        if(row == -1) return false;
        
        vector<int> rowVec;
        helperStore(row, matrix, rowVec);
        
        int low = 0, high = rowVec.size()-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(rowVec[mid] == target) return true;
            else if(rowVec[mid] > target){
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        
        return false;
    }
    
    void helperStore(int row, vector<vector<int>>& matrix, vector<int>& rowVec){
        
        for(int i=0; i<matrix[0].size(); i++){
            rowVec.push_back(matrix[row][i]);
        }
    }
};