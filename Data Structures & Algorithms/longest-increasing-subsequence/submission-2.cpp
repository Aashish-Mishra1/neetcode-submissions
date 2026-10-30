class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>dp;

        int n = nums.size();

        dp.push_back(nums[0]);
        int LIS = 1;
        for(int i=1;i<n;i++){
            
            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
                LIS++;
                continue;
            }

            int ind = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();

            dp[ind]= nums[i];
        }

        return LIS;
    }
};
