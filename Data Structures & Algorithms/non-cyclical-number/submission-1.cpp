class Solution {
public:
    int dss(int n){
        int sum = 0;
        while(n){
            int dig = n %10;
            sum += dig*dig;
            n /=10;
        }
        return sum;
    }
    bool isHappy(int n) {

        int slow = n;
        int fast = dss(n);
        while(slow!=fast){
            slow = dss(slow);
            fast = dss(dss(fast));
        }
        if(slow==1) return true;
        return false;
        
    }
};
