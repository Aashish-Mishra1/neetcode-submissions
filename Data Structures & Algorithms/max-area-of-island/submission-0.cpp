class Solution {
   public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> qu;
        qu.push({row, col});
        int area = 1;

        while (!qu.empty()) {
            auto [r, c] = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int newrow = r + dir[i].first;
                int newcol = c + dir[i].second;

                if (newrow < 0 || newrow >= m || newcol < 0 || newcol >= n ||
                    visited[newrow][newcol] || grid[newrow][newcol] == 0)
                    continue;

                visited[newrow][newcol] = 1;
                qu.push({newrow, newcol});
                area++;
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int maxArea = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]){
                    maxArea = max(maxArea,bfs(i,j,grid,visited));
                }
            }
        }
        return maxArea;
    }
};
