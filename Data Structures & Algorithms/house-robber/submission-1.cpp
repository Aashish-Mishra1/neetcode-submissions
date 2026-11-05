class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>&memo){

        if(ind<0) return 0;
        if(memo[ind]!=-1) return memo[ind];
        // not rob
        int notrob = solve(ind-1,nums,memo);
        int rob = nums[ind] + solve(ind-2,nums,memo);

        return memo[ind] = max(notrob,rob);
    }
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size(),-1);
        return solve(nums.size()-1,nums,memo);
    }
};
