class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> flood;
        
        int value = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        
        if(image[sr][sc] == newColor) return image;
        fill(image,value, sr, sc, newColor, row, col);
        
        return image;
    }
    
    void fill(vector<vector<int>>& image,int value, int i, int j, int newColor, int r, int c) {
        if(i<0 || j<0 || i>=r || j>=c || image[i][j] != value) {
            return;
        }
        
        image[i][j] = newColor;

        fill(image, value, i-1, j, newColor, r, c);   //top
        fill(image, value, i+1, j, newColor, r, c);   //down
        fill(image, value, i, j-1, newColor, r, c);   //left
        fill(image, value, i, j+1, newColor, r, c);   //right
        
    }
};