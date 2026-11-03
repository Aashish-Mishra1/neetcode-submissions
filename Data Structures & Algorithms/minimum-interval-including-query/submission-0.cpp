class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        
        vector<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            que.push_back({queries[i], i});
        }
        
        sort(intervals.begin(), intervals.end());
        sort(que.begin(), que.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> ans(m, -1);
        int j = 0;
        
        for (int i = 0; i < m; i++) {
            int qVal = que[i].first;
            int qIdx = que[i].second;
            
            // Push all intervals that start <= qVal into the min-heap
            while (j < n && intervals[j][0] <= qVal) {
                int size = intervals[j][1] - intervals[j][0] + 1;
                pq.push({size, intervals[j][1]});
                j++;
            }
            
            while (!pq.empty() && pq.top().second < qVal) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                ans[qIdx] = pq.top().first;
            }
        }
        
        return ans;
    }
};
