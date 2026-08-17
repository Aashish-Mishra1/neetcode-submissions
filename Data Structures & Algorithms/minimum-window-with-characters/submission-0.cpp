class Solution {
public:
    bool isValid(unordered_map<char,int>&mp){
        
        for(auto it:mp){
            if(it.second>0) return false;
        }
        return true;

    }
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c:t) mp[c]++;

        int l=0,r=0;
        int n = s.size();
        int minSize = INT_MAX;
        int start = -1;
        while(r<n){
            mp[s[r]]--;

            while(isValid(mp)){
                int len = r-l+1;
                if(len<minSize){
                    minSize = len;
                    start = l;
                }
                mp[s[l]]++;
                l++;
            }

            r++;
        }

        if(start ==-1) return "";
        return s.substr(start,minSize);
    }
};
