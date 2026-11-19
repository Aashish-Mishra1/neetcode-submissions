class Solution {
public:
    int solve(int ind,int amount,vector<int>&coins,vector<vector<int>>&memo){

        if(amount==0) return 1;
        if(ind<0) return 0;
        
        if(memo[ind][amount]!=-1) return memo[ind][amount];
        // nottake
        int nottake = solve(ind-1,amount,coins,memo);

        // take
        int take = 0;
        if(amount>=coins[ind]){
            take = solve(ind,amount-coins[ind],coins,memo);
        }
        return memo[ind][amount]=nottake+take;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>memo(n,vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,memo);
    }
};
