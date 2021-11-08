class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        
        string newString = s + s;
        bool result;
        if(newString.find(goal) != string::npos){
            result =  true;
        } else {
            result = false;
        }
        return result;
    }
};