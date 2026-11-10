class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<int>prev = intervals[0];
        vector<vector<int>>ans;

        for(int i=1;i<n;i++){
            
            if(prev[1]>=intervals[i][0]){
                prev[0] = min(prev[0],intervals[i][0]);
                prev[1] = max(prev[1],intervals[i][1]);
            }
            else{
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
