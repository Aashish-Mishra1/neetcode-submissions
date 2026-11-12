class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        vector<int>prices(n,1e9);
        queue<vector<int>>qu;
        qu.push({src,0,0});
        prices[src] = 0;

        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            int port = it[0];
            int cost = it[1];
            int stops = it[2];

            if(stops == k+1) continue;

            for(auto neigh:adj[port]){
                int np = neigh.first;
                int price = neigh.second;

                if(cost+price<prices[np]){
                    prices[np] = cost + price;
                    qu.push({np,prices[np],stops+1});
                }
            }
        }
        if(prices[dst]==1e9) return -1;
        return prices[dst];
    }
};
