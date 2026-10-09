class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int,int>> posSpeed(n);

        for(int i=0;i<n;i++){
            posSpeed[i] = {position[i],speed[i]};
        }

        sort(posSpeed.begin(),posSpeed.end(),greater<pair<int,int>>());

        int count = 0;
        double lastTime = 0;

        for(int i=0;i<n;i++){
            auto [pos,sped] = posSpeed[i];

            double time = (double)(target-pos)/(double)sped;

            if(time>lastTime){
                count++;
                lastTime = time;
            }
        }

        return count;
    }
};
