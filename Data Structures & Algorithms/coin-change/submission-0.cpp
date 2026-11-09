class Solution {
public:
    int helper(int ind,int amount,vector<int>&coins){

        if(amount == 0) return 0;
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }

        // not take
        int nottake = helper(ind-1,amount,coins);
        // take 
        int take = 1e9;

        if(coins[ind]<=amount){
            take = 1 + helper(ind,amount-coins[ind],coins);
        }

        return min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int ans =  helper(n-1,amount,coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};
