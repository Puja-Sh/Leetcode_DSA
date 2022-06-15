class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int sSize = s.length(), subSize = sub.length(), mappingsSize = mappings.size();
        
        unordered_map<char, unordered_set<char>> mp;
        
        // Convert mappings into unordered map with key and value(alternative options of char)
        for(int i=0; i<mappingsSize; i++){
            mp[mappings[i][0]].insert(mappings[i][1]);
        }
        
        // Compare substring of sub length to the main string s
        // Conditions to check the non possibility->
        // if s != sub then check in map
        // if map find sub == end (means the sub[j] in not present so we can't get the alternative options)
        // if map[sub] find s == end (means sub[j] is present but required alternatice option is not present)

        for(int i=0; i<=sSize-subSize; i++){
            int j;
            for(j=0; j<subSize; j++){
                
                if(s[i+j] != sub[j] && (mp.find(sub[j]) == mp.end() || mp[sub[j]].find(s[i+j]) == mp[sub[j]].end() )) {
                    
                   break;
                }                     
            }
            if(j == subSize){
                return true;
            }
        }
        
        return false;
    }
};