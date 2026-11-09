class Solution {
public:
    void helper(int ind,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }

        // skip
        helper(ind+1,nums,temp,ans);

        // take
        temp.push_back(nums[ind]);
        helper(ind+1,nums,temp,ans);
        temp.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>temp;
        vector<vector<int>>ans;

        helper(0,nums,temp,ans);
        return ans;
    }
};
