class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++) {
            
            if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
                
            } else {
                if(st.empty()) return false;
                else if(helper(st, s[i]) == false) return false;   
                else {
                    st.pop();
                }
            }
        }

        bool res = st.empty();

        return res;
    }
    
    bool helper(stack<char>& st, char c){

        if(c == ')' && st.top() == '(') return true;
        else if(c == ']' && st.top() == '[') return true;
        else if(c == '}' && st.top() == '{') return true;
        
        return false;
    }
};