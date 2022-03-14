class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); ++i) {
            if(path[i] == '/')    
                continue;
            string temp;
            
			// iterate till we doesn't traverse the whole string and doesn't encounter the last '/''
            while(i < path.size() && path[i] != '/') {				
                temp += path[i];    // add path to temp string
                ++i;
            }
            
            if(temp == ".")
                continue;
			
            else if(temp == "..") { // pop the top element from stack if exists
                if(!st.empty()) {
                    st.pop();
                }
            }
            
            else st.push(temp);			// push the directory file name to stack
        }
        
		
        while(!st.empty()) {     // adding all the stack elements to res
            res = "/" + st.top() + res;
            st.pop();
        }
        
		
        if(res.size() == 0)     // if no directory or file is present
            return "/";
        
        return res;
    }
};