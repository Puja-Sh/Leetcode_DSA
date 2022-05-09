class Solution {
public:       
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0) return {};
        
        map<int, string> m;
        m[2]="abc";
        m[3]="def"; 
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        
        return helper(digits, 0, m);
    }
    
    vector<string> helper(string dig, int i, map<int, string> m){
        
        if(i == dig.size()) return {""};
        
        vector<string> temp = helper(dig, i+1, m);
        
        vector<string> ans;
        
        for(auto x: m[dig[i] - '0']){
            
            for(auto el: temp){
                ans.push_back(x+el);
            }
        }
        
        return ans;
    }
};