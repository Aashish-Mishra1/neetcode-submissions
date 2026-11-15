class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        vector<pair<int,int>>dir = {
            {-1,0},{1,0},{0,1},{0,-1}
        };
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>qu;
        qu.push({0,0,0});
        dist[0][0] = 0;
        while(!qu.empty()){
            auto it = qu.top();
            qu.pop();
            int diff  = it[0];
            int r = it[1];
            int c = it[2];
            if(r==rows-1 && c==cols-1) return diff;
            
            for(int i=0;i<4;i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;
                if(nr<0 || nr>= rows || nc<0 || nc>=cols) continue;

                // visited[nr][nc] = 1;
                int newDiff = max(diff, abs(heights[r][c] - heights[nr][nc]));
                if (newDiff < dist[nr][nc]) {
                    dist[nr][nc] = newDiff;
                    qu.push({newDiff, nr, nc});
                }
            }
        }
        return 0;
    }
};