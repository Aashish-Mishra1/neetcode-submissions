class Solution {
public:
    int binary_search(vector<int>&nums,int low,int high,int target){

        // int ans = -1;

        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {

        // find pivot
        
        int low = 0;
        int high= nums.size()-1;
        int n = nums.size();
        int pivot = 0;
        while(low<=high){
            
            int mid = (high-low)/2 + low;

            if(mid>0 && nums[mid]<nums[mid-1]){
                pivot = mid;
                break;
            }
            else if(nums[mid]>=nums[0]) low = mid+1;
            else high = mid-1;
        }

        // return pivot;
        // if(target<nums[pivot]) return -1;

        if(pivot==0) return binary_search(nums,0,n-1,target);
        if(target>=nums[0]) return binary_search(nums,0,pivot-1,target);
        return binary_search(nums,pivot,n-1,target);
    }
};
