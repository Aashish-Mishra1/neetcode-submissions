class Solution {
public:
    int msb(int num){
        int msb = 0;
        for(int i=0;i<32;i++){
            if(num&(1<<i)){
                msb = i;
            }
        }
        return (1<<msb);
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==0) return 0;
        int a = msb(left);
        int b = msb(right);
        // cout<<a<<" "<<b<<endl;
        if(a!=b) return 0;
        int ans = left;
        for(int i=left;i<=right;i++){
            ans &=i;
        }
        return ans;

        // if(a==b) return a;
        // return 0;
    }
};