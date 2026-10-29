class Solution {
   public:
    int helper(int i, vector<int>& memo) {
        // basecase
        if (i == 0) return 1;
        if (i < 0) return 0;

        if (memo[i] != -1) return memo[i];

        int byOneStep = helper(i - 1, memo);
        int byTwoStep = helper(i - 2, memo);

        return memo[i] = byOneStep + byTwoStep;
    }
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        // return helper(n,memo);

        memo[0] = 1;

        for (int i = 1; i <= n; i++) {
            int byOneStep = (i-1>=0)?memo[i - 1]:0;
            int byTwoStep = (i-2>=0)?memo[i - 2]:0;

            memo[i] = byOneStep + byTwoStep;
        }

        return memo[n];
    }
};
