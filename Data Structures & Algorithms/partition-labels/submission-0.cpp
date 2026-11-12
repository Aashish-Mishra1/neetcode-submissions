class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.size();
        map<char,int> mp;

        for(int i=n-1;i>=0;i--){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = i;
            }
        }

        vector<int>ans;
        int left = 0;
        int right = 0;
        int maxRange = mp[s[0]];
        while(right<n){
            while(right<n && right<maxRange){
                maxRange = max(maxRange,mp[s[right]]);
                cout<<right<<" "<<maxRange<<endl;
                right++;  
            }

            ans.push_back(right-left+1);
            right++;
            if(right<n)
            maxRange = max(maxRange,mp[s[right]]);
            left = right;
        }
        return ans;
    }
};
