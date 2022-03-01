class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        
        res.push_back(0);
        
        if(n == 0) return res;
        
        for(int i=1; i<=n; i++){
            helperBinary(i, res);
        }
        
        return res;
    }
    
    void helperBinary(int i, vector<int>& res){
        int q=0, r=0, sum = 0;
        while(i != 1){
            q = i/2;
            r = i % 2;
            i = q;
            sum+=r;
        }
        sum++;
        res.push_back(sum);
    }
};