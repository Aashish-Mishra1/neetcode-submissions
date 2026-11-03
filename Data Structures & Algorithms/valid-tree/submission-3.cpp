class Solution {
public:
    bool isCycle(int node,int parent,vector<vector<int>>&adj,vector<int>&visited){

        visited[node] = 1;

        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                if(isCycle(neigh,node,adj,visited)) return true;
            }
            else if(neigh!=parent) return true;
        }
        return false;

    }
    bool validTree(int n, vector<vector<int>>& edges) {

        int m = edges.size();
        if(m>=n || m<n-1) return false;

        vector<vector<int>>adj(n);

        for(auto edg:edges){
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }
        vector<int>visited(n);

        for(int i=0;i<n;i++){
            if(!visited[i])
        if(isCycle(i,-1,adj,visited)) return false;
        }
        return true;


    }
};
