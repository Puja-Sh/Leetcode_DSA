class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') {
                st.push(0);
            } else {
                int val = 0;
                if(st.top() == 0){
                    val = 1;
                } else {
                    val = st.top()*2;
                }
                st.pop();
                st.top() += val;
            }
        }
        return st.top();
    }
};