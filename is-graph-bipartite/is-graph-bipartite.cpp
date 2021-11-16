class Solution {
public:
    // i - adj....
    // 0 - 1 2 3 
    // 1 - 0 2
    // 2 - 0 1 3
    // 3 - 0 2
    
    // colored = 1 and -1
    // uncolored = 0
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> colors(len, 0);
        
        for(int i=0; i<len; i++) {   // 0 1 2 3
            if(colors[i] == 1 || colors[i] == -1){ // means colored so continue
                continue;
            }
            
            queue<int> q;
            q.push(i);      // node i
            colors[i] = 1; // set color to 1
            
            while(!q.empty()){
                int curr = q.front();   // must be colored
                q.pop();
                for(auto adj:graph[curr]) { // 0=> adj = 1 2 3  
                    
                    if(colors[adj] == 0){   // if not colored then push the node and colored opposite previous node
                        q.push(adj);
                        colors[adj] = -colors[curr];
                    }
                    
                    if(colors[adj] == colors[curr]){  // checking if it was colored then was it same with previous or not
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};