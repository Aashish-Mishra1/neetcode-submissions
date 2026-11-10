class Solution {
public:
    int totalSum = 0;

    int helper(int ind, int sum, int target, vector<int>& nums, vector<vector<int>>& memo) {
        if (ind < 0) {
            return sum == target;
        }

        if (memo[ind][sum + totalSum] != -1) 
            return memo[ind][sum + totalSum];

        int plusWay = helper(ind - 1, sum + nums[ind], target, nums, memo);
        int minusWay = helper(ind - 1, sum - nums[ind], target, nums, memo);

        return memo[ind][sum + totalSum] = plusWay + minusWay;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (abs(target) > totalSum) return 0;
        
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(2 * totalSum + 1, -1));
        
        return helper(n - 1, 0, target, nums, memo);
    }
};
