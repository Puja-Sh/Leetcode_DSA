class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int j = 0; 
        
        for(int i=0; i<n; i++){
            st.push(pushed[i]);
            
            while(!st.empty() && j < popped.size() && popped[j] == st.top()){
                st.pop();
                j++;  
            }
        }
        
        if(st.empty()) return true;
        
        return false;
    }
};