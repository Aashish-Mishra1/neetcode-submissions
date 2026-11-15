class Solution {
public:
    string reorganizeString(string s) {

        vector<int>freq(26);
        for(char ch:s){
            freq[ch-'a']++;
        }

        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],i});
            }
        }
        string res = "";
        pair<int,int> prev = {-1,-1};
        while(!pq.empty()){
            auto [count,ch] = pq.top();
            pq.pop();
            res += char(ch+'a');
            count--;
            if(prev.first>0) pq.push(prev);
            prev = {count,ch};
        }

        if(res.size()==s.size()) return res;
        return "";
        
    }
};