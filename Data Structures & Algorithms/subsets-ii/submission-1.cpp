class Solution {
public:
    void solve(int ind,vector<int>&temp,set<vector<int>>&st,vector<int>&nums){

        if(ind<0){
            vector<int> temp1 = temp;
            sort(temp1.begin(),temp1.end());
            st.insert(temp1);
            return;
        }

        // skip
        solve(ind-1,temp,st,nums);
        temp.push_back(nums[ind]);
        solve(ind-1,temp,st,nums);
        temp.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        

        set<vector<int>>st;
        vector<int>temp;

        solve(nums.size()-1,temp,st,nums);
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
