class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> ans(8);
        ans[0] = 0;
        ans[7]=0;

        // As per the rule for occupied or vacat, there should a cycle
        // where the sequence repeats, need to find out that. When
        // evaluated with different examples it is seen that sequence is
        // repeated at every 14 days ie.., day 1 repeats at 15th day and
        // so on. Based on this if the first 14 days are there, we can get
        // for any n value.
        // N will be mod of 14
        n = (n % 14 == 0) ? 14 : (n % 14);
        
        while( n > 0){
          for(int i=1; i<7; i++){
              ans[i] = cells[i-1] == cells[i+1] ? 1 : 0;
              cells[i-1] = ans[i-1];
          }
            cells[6] = ans[6];
            cells[7] = ans[7];
            n--;
        }
      
        
        return ans;
    }
};