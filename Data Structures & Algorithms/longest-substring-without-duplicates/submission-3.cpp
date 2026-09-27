class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> present(256,-1);
        int left=0,right=0,ans=0;
        while(right<s.size()){
            if(present[s[right]]>=0 && left<=present[s[right]]){
                left = present[s[right]]+1;
            }
            present[s[right]] = right;
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
