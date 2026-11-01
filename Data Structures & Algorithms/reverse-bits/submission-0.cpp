class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        string reversed = "";
        int res = 0;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                reversed += '1';
                res += (1<<(31-i));
            }
            else{
                reversed += '0';
            }
        }
        return res;
    }
};
