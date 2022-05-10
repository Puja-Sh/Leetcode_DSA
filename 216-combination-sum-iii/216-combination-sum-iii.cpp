class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        
        combination(1, n, k, temp, result);
        
        return result;
    }
    
    void combination(int start, int leftSum, int k, vector<int> temp, vector<vector<int>>& result){
        
        if(temp.size() == k){           // If reached to length of k
            
            // AND if picked elements giving left Sum = 0 means no greater or lesser value required to make the sum == n
            if(leftSum == 0){           
                result.push_back(temp);     // So push the temp to result
            }
        }
        
        if(leftSum < 0) return;
        
        for(int i = start; i<=9; i++){      // we'll always start from start+1 because we need unique value only
            
            temp.push_back(i);
            start++;
            
            combination(start, leftSum-i, k, temp, result);
            
            temp.pop_back();
        }
    }
};