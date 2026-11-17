class DSU{
private:
    vector<int>parent;
    vector<int>rank;

public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        } 
    }

    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu==pv) return;
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
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        
        int n = nums.size();

        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(__gcd(nums[i],nums[j])>1){
                    dsu.unionByRank(i,j);
                }
            }
        }

        int count =0;
        for(int i=0;i<n;i++){
            if(dsu.findParent(i)==i) count++;
        }
        return count==1;
    }
};