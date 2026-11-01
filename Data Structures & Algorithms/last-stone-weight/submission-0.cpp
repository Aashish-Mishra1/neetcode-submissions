class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq(stones.begin(),stones.end());

        while(pq.size()>1){

            int h1 = pq.top();
            pq.pop();
            int h2 = pq.top();
            pq.pop();

            if(h1!=h2)
                pq.push(h1-h2);

        }

        if(pq.empty()) return 0;
        return pq.top();

    }
};
