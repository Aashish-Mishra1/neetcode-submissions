class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN;
        int prefixSum = 0;
        int minPrefixSum = 0;
        for(auto num:nums){
            prefixSum += num;
            maxSum = max(maxSum,prefixSum-minPrefixSum);

            minPrefixSum = min(minPrefixSum,prefixSum);

        }
        return maxSum;
    }
};
