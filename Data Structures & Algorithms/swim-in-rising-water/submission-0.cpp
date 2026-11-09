class Solution {
public:
   
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int,int>>visited;
        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

        pq.push({grid[0][0],0,0});
        visited.insert({0,0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int maxVal = it[0],r=it[1],c=it[2];

            if(r==m-1 && c==n-1) return maxVal;

            for(int i=0;i<4;i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;
                
                if(nr<0 || nr>=m || nc<0 || nc>=n || visited.count({nr,nc})) continue;

                visited.insert({nr,nc});
                pq.push({max(maxVal,grid[nr][nc]),nr,nc});
            }
        }
        
    }
};
