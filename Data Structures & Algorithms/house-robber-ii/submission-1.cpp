class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];
        // nottake
        int nottake = solve(ind+1,nums,dp);

        // take
        int take = nums[ind]+solve(ind+2,nums,dp);

        return dp[ind] = max(take,nottake);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        // n--;
        vector<int>dp2(n,-1);
        int robWithEnd = solve(1,nums,dp1);
        nums.pop_back();
        int robWithoutEnd = solve(0,nums,dp2);

        return max(robWithEnd,robWithoutEnd);
        
    }
};
