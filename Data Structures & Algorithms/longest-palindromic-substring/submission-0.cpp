class Solution {
public:
    // returning start and length

    pair<int,int> helper(int left,int right,string& s){
        
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }

        return {left+1,right-left-1};
    }
    string longestPalindrome(string s) {
        
        int maxStart = -1;
        int maxSize = 0;

        for(int i=0;i<s.size();i++){

            auto [oddstart,oddlen] = helper(i,i,s);
            if(oddlen>maxSize){
                maxSize = oddlen;
                maxStart = oddstart;
            }
            auto [evenstart,evenlen] = helper(i,i+1,s);
            if(evenlen>maxSize){
                maxSize = evenlen;
                maxStart = evenstart;
            }
            
        }

        return s.substr(maxStart,maxSize);
    }
};
