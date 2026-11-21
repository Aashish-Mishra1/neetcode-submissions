class Solution {
   public:
    bool solve(int ind, string s, unordered_set<string>& st,vector<int>&memo) {
        if (ind == s.size()) return true;
        if(memo[ind]!=-1) return memo[ind];
        for (int i = ind; i < s.size(); i++) {
            // cout<<ind<<" "<<i<<" ";
            // cout << s.substr(ind, i - ind + 1) << endl;
            if (st.find(s.substr(ind, i - ind + 1)) != st.end()) {
                // cout << s.substr(ind, i - ind + 1) << endl;
                if (solve(i + 1, s, st,memo)) return memo[ind] = true;
            }
        }
        return memo[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int>memo(n,-1);
        return solve(0, s, st,memo);
    }
};
