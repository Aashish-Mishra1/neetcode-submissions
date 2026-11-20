class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>indegree(rows*cols);
        vector<vector<int>>adj(rows*cols);
        vector<pair<int,int>>dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                for(int k=0;k<4;k++){
                    int ni = i+dir[k].first;
                    int nj = j+dir[k].second;
                    if(ni<0||ni>=rows||nj<0||nj>=cols) continue;
                    if(matrix[i][j]<matrix[ni][nj]){
                        adj[i*cols+j].push_back(ni*cols+nj);
                        indegree[ni*cols+nj]++;
                    }
                }
            }
        }

        queue<int>qu;
        int size = 0;
        for(int i=0;i<rows*cols;i++){
            if(indegree[i]==0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            int n = qu.size();
            for(int i=0;i<n;i++){
                int node = qu.front();
                qu.pop();
                for(auto neigh:adj[node]){
                    indegree[neigh]--;
                    if(indegree[neigh]==0){
                        qu.push(neigh);
                    }
                }
            }
            size++;
        }
        return size;
    }
};
