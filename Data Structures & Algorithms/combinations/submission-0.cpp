class Solution {
public:
    void solve(int ind,int n,int k,vector<int>&temp,vector<vector<int>>&ans){
        if(ind==k){
            ans.push_back(temp);
            return;
        }
        
        int start = (temp.empty())?0:temp.back();
        for(int i=start+1;i<=n;i++){
            temp.push_back(i);
            solve(ind+1,n,k,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,n,k,temp,ans);
        return ans;
    }
};