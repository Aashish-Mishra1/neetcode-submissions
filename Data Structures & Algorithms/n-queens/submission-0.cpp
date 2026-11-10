class Solution {
public:
    void helper(int row,int n,vector<int>&occupiedCol,vector<int>&negDia,vector<int>&posDia,vector<string>&temp,vector<vector<string>>&ans){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(occupiedCol[i]==0 && negDia[row-i+n-1]==0 && posDia[row+i]==0){
                temp[row][i] = 'Q';
                occupiedCol[i] = 1;
                negDia[row-i+n-1] = 1;
                posDia[row+i] = 1;
                helper(row+1,n,occupiedCol,negDia,posDia,temp,ans);
                temp[row][i]='.';
                occupiedCol[i] = 0;
                negDia[row-i+n-1] = 0;
                posDia[row+i] = 0;
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp;
        vector<vector<string>>ans;
        vector<int>occupiedCol(n);
        vector<int>negDia(2*n-1);
        vector<int>posDia(2*n-1);
        string st = "";
        st.append(n,'.');
        for(int i=0;i<n;i++){
            temp.push_back(st);
        }

        helper(0,n,occupiedCol,negDia,posDia,temp,ans);
        return ans;
    }
};
