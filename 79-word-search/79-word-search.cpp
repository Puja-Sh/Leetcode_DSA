class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == word[0] &&  helper(board, word, 0, i, j)) {
                   return true;
                }
                
            }
        }
        
        return false;
        
    }
    
    bool helper(vector<vector<char>>& board, string& word, int index, int i, int j) { 
         if(index == word.length()) {
            return true;
        }
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[index]){
            return false;
        } 
      
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool found = helper(board,word,index+1,i+1,j) || helper(board,word,index+1,i,j+1) || helper(board,word,index+1,i-1,j) || helper(board,word,index+1,i,j-1);
        
        board[i][j] = temp;
        
        return found;
    }
};