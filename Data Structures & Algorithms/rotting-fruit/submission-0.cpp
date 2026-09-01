class Solution {
public:
    vector<pair<int,int>>moves = {
        {0,1},{0,-1},{1,0},{-1,0}
    };
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>>qu;
        int freshOrenge = 0;
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    qu.push({i,j});
                }
                else if(grid[i][j]==1) freshOrenge++;
            }
        }
        cout<<freshOrenge<<endl;

        if(freshOrenge==0) return time;

        while(!qu.empty()){
            if(freshOrenge==0) return time;
            int x = qu.size();
            for(int i=0;i<x;i++){
                auto [row,col] = qu.front();
                qu.pop();
                for(int j=0;j<4;j++){
                    int nrow = row + moves[j].first;
                    int ncol = col + moves[j].second;

                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || grid[nrow][ncol]!=1) continue; 
                    freshOrenge--;
                    grid[nrow][ncol] = 2;
                    qu.push({nrow,ncol});
                }
            }
            time++;
            cout<<freshOrenge<<endl;
        }
        return -1;
    }
};
