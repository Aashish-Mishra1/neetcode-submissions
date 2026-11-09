class Solution {
public:
    vector<pair<int,int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int INF = INT_MAX;
        queue<pair<int,int>>qu;
        vector<vector<int>>visited(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){ 
                    qu.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        
        

        int moves = 0;
        while(!qu.empty()){
            moves++;

            int x = qu.size();
            cout<<"x: "<<x<<endl;
            for(int i=0;i<x;i++){
                auto [r,c] = qu.front();
                qu.pop();
                cout<<r<<" "<<c<<endl;
                for(int i=0;i<4;i++){
                    int nr = r +dir[i].first;
                    int nc = c +dir[i].second;

                    if(nr<0 || nr>=m || nc<0 || nc>=n || visited[nr][nc]==1 || grid[nr][nc]!=INF) continue;
                    visited[nr][nc] = 1;
                    grid[nr][nc] = moves;
                    qu.push({nr,nc});
                }

            }
        }
    }
};
