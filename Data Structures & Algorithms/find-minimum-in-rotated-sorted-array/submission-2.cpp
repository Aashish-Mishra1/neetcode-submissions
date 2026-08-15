class Solution {
public:
    int findMin(vector<int> &nums) {

        int low = 0;
        int high = nums.size()-1;

        int ans;
        while(low<=high){
            int mid = (high+low)/2;

            if(mid>0 && nums[mid]<nums[mid-1]) return nums[mid];
            else if(nums[mid]>=nums[0]) low = mid+1;
            else high = mid-1;

        }

        return nums[0];
        
    }
};
