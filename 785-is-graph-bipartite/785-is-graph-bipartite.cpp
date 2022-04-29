class Solution {
public:
    // graph coloring BFS solution
    
    //color = 0 (not colored)
    //color = 1 (blue)
    //color = -1 (red)
    
    //TC - O(V+E)       SC - O(V)
    
    bool isBipartite(vector<vector<int>>& graph) {
        int nodesSize = graph.size();
        vector<int> color(nodesSize, 0);       
        
        for(int i=0; i<nodesSize; i++){
            
            if(color[i]==0){     // check if not colored
                queue<int> q;
                q.push(i);
                
                color[i] = 1;   // change color to 1 (and its adj will be -1)
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(auto n : graph[node]){
                        if(color[n] == 0){
                            q.push(n);                      // adding to queue
                            color[n] = -color[node];        // adj color will be opp of parent node
                            
                        } else if(color[n] == color[node]){ // if parent and adj have same color RETURN FALSE
                            return false;
                        }
                    }
                }
            }
            
        }
        
        
        return true;
    }
};