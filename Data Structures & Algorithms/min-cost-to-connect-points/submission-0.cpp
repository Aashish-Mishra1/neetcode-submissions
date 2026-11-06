class DSU{
    private:
       vector<int>parent;
       vector<int>rank;
    
    public:
       DSU(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
       }

       int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
       }

       void unionByRank(int u, int v){

        int pu = findParent(u);
        int pv = findParent(v);

        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pu]= pv;
            rank[pv]++;
        }
       }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<pair<int,pair<int,int>>> dists;

        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                dists.push_back({dist,{i,j}});
            }
        }

        sort(dists.begin(),dists.end());

        DSU dsu = DSU(n);
        int ans = 0;
        for(auto it:dists){
            int dis = it.first;
            auto [i,j] = it.second;

            int pi = dsu.findParent(i);
            int pj = dsu.findParent(j);

            if(pi==pj) continue;
            else{
                ans += dis;
                dsu.unionByRank(i,j);
            }
        }
        return ans;
    }
};
