class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        st.push({s[0],1});
        
        for(int i=1; i<s.length(); i++){
            
            if(!st.empty() && st.top().first == s[i]){
                int count = st.top().second+1;
                st.pop();
                st.push({s[i], count});
                
                if(count == k){
                    st.pop();
                }
            } else {
                st.push({s[i], 1});
            }
        }
        
        string result;
        
        while(!st.empty()){
            while(st.top().second--){
                result+=st.top().first;
            }
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};