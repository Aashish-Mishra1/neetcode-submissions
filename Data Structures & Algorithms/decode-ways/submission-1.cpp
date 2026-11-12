class Solution {
public:
    int helper(int ind,string& s,vector<int>&memo){
        if(ind>=s.size()) return 1;
        if(s[ind]=='0') return 0;

        if(memo[ind]!=-1) return memo[ind];
        // one char
        int oneChar = helper(ind+1,s,memo);

        // two char
        int twoChar = 0;
        if(ind+1<s.size()){
            int num = stoi(s.substr(ind,2));
            if(num>=1 && num<=26){
                twoChar = helper(ind+2,s,memo);
            }
        }

        return memo[ind]=oneChar+twoChar;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>memo(n,-1);
        return helper(0,s,memo);
    }
};
