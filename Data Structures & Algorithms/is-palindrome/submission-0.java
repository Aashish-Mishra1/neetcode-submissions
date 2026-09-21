class Solution {
    static boolean isValideChar(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) return true;
        return false;
    }
    
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
            if (isValideChar(s.charAt(left)) == false) {
                left++;
            }
            else if (isValideChar(s.charAt(right)) == false) {
                right--;
            }
            else if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                return false;
            }
            else {
                left++;
                right--;
            }
        }

        return true;
    }
}
