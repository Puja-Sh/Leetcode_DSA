class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            char c = input[i];
            
            if(c=='+'||c=='*'||c=='-'){
                string left = input.substr(0,i);        // dividing left part string
                string right = input.substr(i+1);       // dividing right part string
                
                vector<int> leftPart = diffWaysToCompute(left);     // recursion call for left part string
                vector<int> rightPart = diffWaysToCompute(right);   // recursion call for right part string
                
                for(int x : leftPart){          
                    for(int y : rightPart){
                        
                        if(c=='-'){
                            ans.push_back(x-y);
                        }else if(c=='*'){
                            ans.push_back(x*y);
                        } else if(c=='+'){
                            ans.push_back(x+y);
                        }
                    }
                }
                
                
            }
        }
        
        if(ans.size()==0){    // after reaching end where ans size = 0, convert that input (with size=1) stoi and push into ans and return it
            ans.push_back(stoi(input));
        }
        
        return ans;
    }
};