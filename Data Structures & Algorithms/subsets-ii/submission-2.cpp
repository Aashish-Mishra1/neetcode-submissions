class Solution {
public:
    void solve(int ind,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){

        if(ind<0){
            ans.push_back(temp);
            return;
        }

        // skip
        temp.push_back(nums[ind]);
        solve(ind-1,temp,ans,nums);
        temp.pop_back();

        // skip
        while(ind-1>=0 && (nums[ind-1]==nums[ind])) ind--;

        solve(ind-1,temp,ans,nums);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        

        // set<vector<int>>st;
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(nums.size()-1,temp,ans,nums);
        return ans;
    }
};
