class Solution {
public:

    vector<pair<int,int>> dir = {
        {0,1},{0,-1},{1,0},{-1,0}
    };
    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        qu.push({row,col});
        visited[row][col] = 1;

        while(!qu.empty()){

            auto [r,c] = qu.front();
            qu.pop();

            for(int i=0;i<4;i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                if(nr<0 || nr>=m || nc<0 || nc>=n || (grid[nr][nc]=='0') || visited[nr][nc]) continue;

                visited[nr][nc] = 1;
                qu.push({nr,nc});
                
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(i,j,grid,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};
