class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>indegrees(numCourses);
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }

        vector<int>order;
        queue<int>qu;
        for(int i=0;i<numCourses;i++){
            if(indegrees[i]==0) qu.push(i);
        }

        while(!qu.empty()){
            int course = qu.front();
            qu.pop();
            order.push_back(course);
            for(auto depCourse:adj[course]){
                indegrees[depCourse]--;
                if(indegrees[depCourse]==0) qu.push(depCourse);
            }
        }

        return order.size()==numCourses;
    }
};
