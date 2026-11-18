class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int left = 0;
        int right = nums.size()-1;
        int minEle = INT_MAX;
        while(left<=right){
            int mid = (left+right)/2;

            if(nums[mid]<=nums[right]){
                minEle = min(minEle,nums[mid]);
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return minEle;
    }
};
