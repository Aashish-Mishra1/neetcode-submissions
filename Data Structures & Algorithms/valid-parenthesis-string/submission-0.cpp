class Solution {
public:
    bool checkValidString(string s) {
        
        // int count = 0;
        int maxi = 0;
        int mini = 0;

        for(auto ch:s){
            if(ch=='('){
                maxi++;
                mini++;
            }
            else if(ch==')'){
                maxi--;
                mini--;
            }
            else{
                maxi++;
                mini--;
            }

            if(maxi<0) return false;
            if(mini<0) mini = 0;
        }
        // return true;

        if(mini>0) return false;
        return true;
    }
};
