class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        int m = edges.size();

        if(m>=n || m<n-1) return false;

        vector<vector<int>>adj(n);

        for(auto edg:edges){
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }

        vector<int>visited(n);

        queue<int>qu;
        qu.push(0);
        visited[0] = 1;

        while(!qu.empty()){
            int node = qu.front();
            qu.pop();

            for(auto neigh:adj[node]){
                if(visited[neigh]==0){
                    qu.push(neigh);
                    visited[neigh] =1;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};
