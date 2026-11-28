class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1;
        int count = 0;

        for(auto num:nums){
            if(num==ans){
                count++;
            }
            else{
                // count--;
                if(count<=0){
                    ans = num;
                    // count++;
                }
                else count++;
            }
        }
        return ans;
    }
};