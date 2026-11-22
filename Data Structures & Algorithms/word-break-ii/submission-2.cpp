class Solution {
public:
    void solve(int ind,string& s,string st,vector<string>&ans,unordered_set<string>&wst){

        if(ind==s.size()){
            ans.push_back(st);
            return;
        }

        for(int i=ind;i<s.size();i++){

            if(wst.find(s.substr(ind,i-ind+1))!=wst.end()){
                string temp = "";
                if(st.size()==0){
                    temp= s.substr(ind,i-ind+1);
                }
                else{
                    temp= ' '+s.substr(ind,i-ind+1);
                }
                solve(i+1,s,st+temp,ans,wst);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_set<string>wst(wordDict.begin(),wordDict.end());
        string st = "";
        solve(0,s,st,ans,wst);
        return ans;
    }
};