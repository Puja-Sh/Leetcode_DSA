class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> adjList(n);
        
        // adjacency List / Making graph
        // 0 -> 1 -> 2
        // 1 -> 0 -> 2
        // 2 -> 1 -> 0
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        // BFS Method
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            if(top == end) { // reached the end
                return true;
            }        
            
            for(int i=0; i<adjList[top].size(); i++){   // iterate over each index of 2d vector and checking whether its visited or not
                if(visited[adjList[top][i]] == 0) {
                    q.push(adjList[top][i]);
                    visited[adjList[top][i]] = 1;
                }
            }
        }
        
        return false;
    }
};