class Solution {
public:
    int helper(int ind1,int ind2,string& word1,string& word2,vector<vector<int>>&memo){

        // basecase
        if(ind2>=word2.size()) return word1.size()-ind1;
        if(ind1>=word1.size()) return word2.size()-ind2;
        if(memo[ind1][ind2]!=-1) return memo[ind1][ind2];
        int ops = 0;
        // match
        if(word1[ind1]==word2[ind2])
        ops = helper(ind1+1,ind2+1,word1,word2,memo);
        else{
            ops = 1 + min(helper(ind1,ind2+1,word1,word2,memo),min(helper(ind1+1,ind2,word1,word2,memo),helper(ind1+1,ind2+1,word1,word2,memo)));
        }
        return memo[ind1][ind2] = ops;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,memo);
    }
};
