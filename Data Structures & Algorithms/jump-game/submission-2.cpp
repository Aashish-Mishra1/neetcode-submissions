class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxReach = 0;

        for(int i=0;i<nums.size();i++){
            maxReach = max(maxReach,i+nums[i]);

            if(maxReach>=nums.size()-1) return true;
            if(maxReach<=i) return false;
        }
        return true;
    }
};
