class Solution {
public:
    int noOfSetBits(int n){
        int count = 0;
        while(n){
            count++;
            n &=(n-1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1);

        // ans[0] = 0;
        for(int i=0;i<=n;i++){
            ans[i] = noOfSetBits(i);
        }
        return ans;
    }
};
