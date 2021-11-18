class Solution {
public:
    // TC: O(V+E)
    
    // processed: 1
    // processing: 2
    // not visited: 0
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<prereq.size(); i++) {        // making graph with adj list
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        
        vector<int> visited(numCourses,0);  // visited vector inialized with 0
        
        // 0 to numCourses check whether is it visited or not,
        // checking in other function it's adjacent are making cyclic or not
        for(int i=0;i<numCourses; i++){     
            if(visited[i] == 0){
                if(helperCyclic(adj, visited, i)){ // if true means making cyclic
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helperCyclic(vector<vector<int>>& adj, vector<int>& visited, int idx){
        if(visited[idx] == 2) return true;      // if processed then we need to update it with 1
        
        visited[idx] = 2;       // prccessing
        
        for(int i=0; i<adj[idx].size(); i++) {
            if(visited[adj[idx][i]] != 1){      // != 1 means not processed still processing or not visited
                if(helperCyclic(adj, visited, adj[idx][i])){
                    return true;
                }                
            }
        }
        
        visited[idx] = 1;   // processed
        return false;
    }
};