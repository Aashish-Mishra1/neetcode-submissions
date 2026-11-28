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
                if(count<=0){
                    ans = num;
                }
                else count--;
            }
        }
        return ans;
    }
};