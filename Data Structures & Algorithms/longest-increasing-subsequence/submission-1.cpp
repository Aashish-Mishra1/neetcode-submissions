class Solution {
public:
    int helper(int ind,int last,vector<int>&nums,vector<vector<int>>&memo){

        // basecase
        if(ind<0) return 0;
        if(memo[ind][last]!=-1) return memo[ind][last];

        int nottake = helper(ind-1,last,nums,memo);
        int take = 0;
        if(last==nums.size() || nums[last]>nums[ind]){
            take = 1 + helper(ind-1,ind,nums,memo);
        }
        return memo[ind][last] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>memo(n,vector<int>(n+1,-1));
        return helper(n-1,n,nums,memo);
    }
};
