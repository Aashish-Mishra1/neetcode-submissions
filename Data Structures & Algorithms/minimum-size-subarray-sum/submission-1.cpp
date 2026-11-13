class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int sum = 0;
        int minSize = INT_MAX;
        while(right<n){
            sum += nums[right];

            while(sum>=target){
                minSize = min(minSize,right-left+1);
                sum -= nums[left];
                left++;
            }

            right++;
        }
        if(minSize==INT_MAX) return 0;
        return minSize;
    }
};