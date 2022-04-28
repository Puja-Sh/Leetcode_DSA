class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(row == 0) return ans;
        
        int total = row*col;    // will help to stop when we traverse the all the elements
        int count = 0;          // count the number of element we have pushed inside the answer
        
        int left=0, right=col-1, top=0, bottom=row-1;
        
        while(count < total){
            
            for(int i=left; count<total && i<=right; i++){      // left to right with top (constant)
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            
            for(int i=top; count<total && i<=bottom; i++){      // top to bottom with right (constant)
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            
            for(int i=right; count<total && i>=left; i--){      // right to left with bottom (constant)
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            
            for(int i=bottom; count<total && i>=top ;i--){      // bottom to top with left (constant)
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};

//     l               r
// t   00  01  02  03  04
//     10  11  12  13  14
//     20  21  22  23  24
// b   30  31  32  33  34

// l = left     - y is changing     
// r = right    - y is changing
// t = top      - x is changing
// b = bottom   - x is changing



