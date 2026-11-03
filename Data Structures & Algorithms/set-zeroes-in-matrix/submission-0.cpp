class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        unordered_set<int>rowswithzero;
        unordered_set<int>colswithzero;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rowswithzero.insert(i);
                    colswithzero.insert(j);
                }
            }
        }
        for(auto row:rowswithzero){
            for(int i=0;i<n;i++){
                matrix[row][i] = 0;
            }
        }
        for(auto col:colswithzero){
            for(int i=0;i<m;i++){
                matrix[i][col] = 0;
            }
        }
    }
};
