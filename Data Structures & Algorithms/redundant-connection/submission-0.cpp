class DSU{
private:
    vector<int> rank;
    vector<int>parent;

public:
    DSU(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    bool unionByRank(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv) return false;

        if(rank[pu]>rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for(auto edg:edges){
            if(dsu.unionByRank(edg[0],edg[1])==false) return edg;
        }
        return {};
    }
};
