class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>>adj(26);
        // vector<int>indegree(26);
        unordered_map<int,int> indegree;
        for(auto word:words){
            for(auto ch:word){
                indegree[ch-'a'] = 0;
            }
        }
        int count = indegree.size();
        

        int n = words.size();
        for(int i=0;i<n-1;i++){
            
            // int minLen = min(words[i].size(),words[i+1].size());
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() &&
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            int j=0;
            while(j<minLen){
                if(words[i][j]==words[i+1][j]) j++;
                else{
                    adj[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                    indegree[words[i+1][j]-'a']++;
                    break;
                }
            }
            // if(j>=minLen) return "";
        }

        queue<int>qu;
        for(int i=0;i<26;i++){
            if(indegree.find(i)!=indegree.end() && indegree[i]==0) qu.push(i);
        }
        string ans = "";
        while(!qu.empty()){

            int ch = qu.front();
            qu.pop();
            ans += char(ch+'a');

            for(auto neigh:adj[ch]){
                indegree[neigh]--;
                if(indegree[neigh]==0) qu.push(neigh);
            }
        }
        if(ans.size()==count) return ans;
        return "";
        
    }
};
