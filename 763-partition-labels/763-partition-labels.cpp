class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        for(int i=0; i<s.length(); i++) {
            m[s[i]] = i;
        }
        
        int prev = -1, max = INT_MIN;
        vector<int> res;
        res.reserve(1000);
        
        for(int i=0; i<s.length(); i++) {

           if( m.find(s[i]) != m.end() && m[s[i]] > max) {         
                max = m[s[i]];
            
            }
            if( max == i){
                res.push_back(max - prev);
                prev = max;
            } 
        }
        return res;        
    }
};