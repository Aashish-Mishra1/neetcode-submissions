class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&memo){
        if(row==0 && col==0) return grid[row][col];
        if(row<0 || col<0) return 1e9;

        if(memo[row][col]!=-1) return memo[row][col];
        int up = grid[row][col] + solve(row-1,col,grid,memo);
        int left = grid[row][col] + solve(row,col-1,grid,memo);
        return memo[row][col] = min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,memo);
    }
};