class Solution {
public:
    double myPow(double x, int n) {
        
        double res = 1;
        bool neg = (n<0);
        n = abs(n);
        while(n){
            if(n%2==1){
                res *= x;
            }
            x *=x;
            n>>=1;
            
        }
        if(neg) return 1.0/res;
        return res;
    }
};
