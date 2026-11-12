class Solution {
public:
    void solve(int ind,vector<int>&nums,set<int>&taken,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }


        for(int i=0;i<nums.size();i++){
            if(taken.count(i)) continue;
            temp.push_back(nums[i]);
            taken.insert(i);
            solve(ind+1,nums,taken,temp,ans);
            temp.pop_back();
            taken.erase(i);
        }
                
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int>taken;
        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(0,nums,taken,temp,ans);
        return ans;
    }
};
