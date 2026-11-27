class Solution {
public:
    long long minEnd(int n, int x) {
        int p1 = 0;  // in result
        int p2 = 0; // n-1;

        n--;
        long long ans =x;

        for(int i=0;i<32;i++){
            while(ans&(1ll<<p1)){
                p1++;
            }
            if(n&(1<<i))
            ans |=(1ll<<p1);
            p1++;
        }
        return ans;
    }
};