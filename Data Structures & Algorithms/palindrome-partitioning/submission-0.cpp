class Solution {
public:
    bool isPalindrom(int left,int right,string& s){

        while(left<right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void helper(int i,string& s,vector<string>& st,vector<vector<string>>&ans ){

        if(i==s.size()){
            ans.push_back(st);
            return;
        }
        
        for(int j=i;j<s.size();j++){
            if(isPalindrom(i,j,s)){
                st.push_back(s.substr(i,j-i+1));
                helper(j+1,s,st,ans);
                st.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>st;
        vector<vector<string>>ans;

        helper(0,s,st,ans);
        return ans;
    }
};
