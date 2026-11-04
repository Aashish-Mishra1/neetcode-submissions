/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        vector<pair<int,int>> events;
        int n = intervals.size();
        for(int i=0;i<n;i++){
            events.push_back({intervals[i].start,1});
            events.push_back({intervals[i].end,-1});
        }

        sort(events.begin(),events.end(),[&](pair<int,int>&p1,pair<int,int>&p2){
            if(p1.first==p2.first) return p1.second<p2.second;
            return p1.first<p2.first;
        });

        int maxRooms = 0;
        int runningSum = 0;
        for(auto it:events){
            runningSum += it.second;
            maxRooms = max(maxRooms,runningSum);
        }
        return maxRooms;
    }
};
