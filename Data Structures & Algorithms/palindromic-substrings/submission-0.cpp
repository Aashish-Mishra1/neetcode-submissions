class Solution {
public:
    int helper(int left,int right,string s){
        int count = 0;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
            count++;
        }

        return count;
    }
    int countSubstrings(string s) {

        int n = s.size();
        int res = 0;
        for(int i=0;i<n;i++){
            res += helper(i,i,s)+helper(i,i+1,s);
            
        }
        return res;
    }
};
