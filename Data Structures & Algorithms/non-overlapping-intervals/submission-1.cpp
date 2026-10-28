class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        int count = 0;
        int n = intervals.size();
        int lastStart = 0;
        int lastEnd = INT_MIN;
        for(int i=0;i<n;i++){
            if(lastEnd>intervals[i][0]){
                count++;
                lastEnd = min(lastEnd,intervals[i][1]);
            }
            else{
                lastEnd = intervals[i][1];
            }
        }

        return count;
    }
};
