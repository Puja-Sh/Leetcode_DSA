class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(int i = 0; i<ops.size(); i++){
            string s = ops[i];
            int vSize = st.size();            
            
            if(s == "C") st.pop();
            else if(s == "D") {
                int prev = st.top();
                st.push(prev*2);
                
            } else if(s == "+"){
                
                int prev1 = st.top();
                st.pop();
                int prev2 = st.top();
                
                int res = prev1+prev2;
                
                st.push(prev1);
                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }
        
        int sum = 0;
        while(!st.empty()){
            sum+=st.top();
            cout<<st.top()<<" ";
            st.pop();
        }
        
        return sum;
    }
};