class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>inDegree(numCourses);
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int>qu;
        vector<int>order;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            auto course = qu.front();
            qu.pop();
            order.push_back(course);

            for(auto depCource:adj[course]){
                inDegree[depCource]--;
                if(inDegree[depCource]==0){
                    qu.push(depCource);
                }
            }
        }

        if(order.size()==numCourses) return order;
        return {};
    }
};
