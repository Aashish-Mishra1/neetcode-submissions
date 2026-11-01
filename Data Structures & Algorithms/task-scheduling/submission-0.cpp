class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        

        vector<int>count(26);

        for(auto task:tasks){
            count[task-'A']++;
        }

        priority_queue<int> pq;
        queue<pair<int,int>> waiting;

        for(auto it:count){
            if(it>0){
                pq.push(it);
            }
        }

        int time = 0;

        while(!pq.empty() || !waiting.empty()){

            time++;

            while(!waiting.empty()){
                auto [cnt,tm] = waiting.front();
                if(tm<=time){
                    pq.push(cnt);
                    waiting.pop();
                }
                else break;
            }

            if(!pq.empty()){
                int tp = pq.top();
                pq.pop();
                tp -=1;
                if(tp>0){
                    waiting.push({tp,time+n+1});
                }
            }
        }
        return time;
    }
};
