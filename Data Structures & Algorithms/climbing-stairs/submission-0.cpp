class Solution {
public:
    int helper(int i,vector<int>&memo){

        // basecase
        if(i==0) return 1;
        if(i<0) return 0;

        if(memo[i]!=-1) return memo[i]; 

        int byOneStep = helper(i-1,memo);
        int byTwoStep = helper(i-2,memo);

        return memo[i] =  byOneStep+byTwoStep;
    }
    int climbStairs(int n) {
        vector<int>memo(n+1,-1);
        return helper(n,memo);

    }
};
