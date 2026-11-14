class Solution {
public:
    int helper(int ind1,int ind2,string& s,string& t,vector<vector<int>>&memo){

        if(ind2<0) return 1;
        if(ind1<0) return 0;

        if(memo[ind1][ind2]!=-1) return memo[ind1][ind2];
        // not take;
        int nottake = helper(ind1-1,ind2,s,t,memo);

        // matching
        int take = 0;
        if(s[ind1]==t[ind2]){
            take = helper(ind1-1,ind2-1,s,t,memo);
        }

        return memo[ind1][ind2] = nottake+take;

    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return helper(s.size()-1,t.size()-1,s,t,memo);
    }
};
