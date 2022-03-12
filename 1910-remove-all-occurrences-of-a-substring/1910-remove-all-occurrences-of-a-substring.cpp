class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n = s.length();
        int m = part.size();
        
        for(int i=0; i<n; i++){
            st.push(s[i]);
            int m2 = m;
            
            if(st.size() >= m && checkHelper(st, part)){
                while(m2--) st.pop();
            }
        }
        
        string res = "";
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    
    bool checkHelper(stack<char> st, string part) {
        int m = part.size();
        
        while(m--){
            if(st.top() != part[m]) return false;
            
            st.pop();
        }
        
        return true;
    }
};