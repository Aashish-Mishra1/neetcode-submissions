class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int leftmax = height[left];
        int rightmax = height[right];
        int ans = 0;
        while(left<=right){
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);

            if(leftmax<=rightmax){
                ans += leftmax-height[left];
                left++;
            }
            else{
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};
