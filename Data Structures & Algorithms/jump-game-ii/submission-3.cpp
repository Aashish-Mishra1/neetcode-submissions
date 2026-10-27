class Solution {
public:
    int jump(vector<int>& nums) {
        
        int lf = 0;
        int rf = 0;
        int steps =0;
        int n = nums.size();
        // if(n==1) return 0;
        while(rf<n-1){

            int farthest = 0;
            for(int j=lf;j<=rf;j++){
                farthest = max(farthest,j+nums[j]);
            }
            lf = rf+1;
            rf = farthest;
            steps++;
        }

        return steps;
    }
};
