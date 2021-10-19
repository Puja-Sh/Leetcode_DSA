class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> m;
        int mod[60] = {0};
        
        // for(int i=0; i<60; i++){
        //     mod[i] = 0;
        // }
        
        for(int i:time) {
            mod[i%60]++;    
        }
        
        int pair = 0;
        for(int i=1; i<30; i++){
            pair = pair + (mod[i]*mod[60-i]);
        }
        
        pair+= sumOfPairs(mod[0]-1) + sumOfPairs(mod[30]-1);
        return pair;      
    }
    
    int sumOfPairs(int n){
        return n*(n+1)/2;
    }
};