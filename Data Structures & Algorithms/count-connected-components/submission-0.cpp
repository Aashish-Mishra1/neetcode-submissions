class Solution {
public:
    void bfs(int src,vector<vector<int>>&adj,vector<int>&visited){

        visited[src] = 1;
        queue<int>qu;
        qu.push(src);

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto neigh:adj[node]){
                if(!visited[neigh]){
                    qu.push(neigh);
                    visited[neigh]=1;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int comps = 0;
        vector<vector<int>>adj(n);
        for(auto edg:edges){
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        vector<int>visited(n);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                comps++;
                bfs(i,adj,visited);
            }
        }
        return comps;
    }
};
