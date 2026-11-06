class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);

        for(auto time:times){
            adj[time[0]].push_back({time[1],time[2]});
        }

        vector<int> minTime(n+1,INT_MAX);

        set<pair<int,int>> st;
        minTime[k] = 0;
        st.insert({0,k});

        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            int time = it.first;
            int node  = it.second;

            for(auto neigh:adj[node]){
                int nn = neigh.first;
                int td = neigh.second;

                if(minTime[nn]>=td+time){

                    if(minTime[nn]!=INT_MAX){
                        st.erase({minTime[nn],nn});
                    }
                    minTime[nn] = td+time;
                    st.insert({minTime[nn],nn});
                }
            }
        }

        // int ans = *max_element(minTime.begin(),minTime.end());
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans,minTime[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};
