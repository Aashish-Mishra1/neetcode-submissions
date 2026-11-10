class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int maxPrd = nums[0];
        int minPrd = nums[0];
        int ans = maxPrd;
        for(int i=1;i<n;i++){
            int temp = maxPrd;
            maxPrd = max(nums[i],max(maxPrd*nums[i],minPrd*nums[i]));
            minPrd = min(nums[i],min(temp*nums[i],minPrd*nums[i]));
            
            ans = max(ans,maxPrd);
        }
        return ans;
    }
};
