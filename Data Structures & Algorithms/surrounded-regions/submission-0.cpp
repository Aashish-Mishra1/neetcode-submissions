class Solution {
public:
    vector<pair<int,int>> dir = {
        {0,1},{0,-1},{-1,0},{1,0}
    };
    void solve(vector<vector<char>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>qu;

        // left and right boundary
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){
                qu.push({i,0});
                visited[i][0] = 1;
            }
            if(grid[i][n-1]=='O'){
                qu.push({i,n-1});
                visited[i][n-1] = 1;
            }
        }
        
        // top-down boundry
        for(int i=1;i<n-1;i++){
            if(grid[0][i]=='O'){
                qu.push({0,i});
                visited[0][i] = 1;
            }

            if(grid[m-1][i]=='O'){
                qu.push({m-1,i});
                visited[m-1][i] = 1;
            }
        }

        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();

            for(int i=0;i<4;i++){
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;

                if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]=='X' || visited[nr][nc] ) continue;

                visited[nr][nc] = 1;
                qu.push({nr,nc});
            }
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]=='O' && visited[i][j]==0){
                    grid[i][j] = 'X';
                }
            }
        }

    }
};
