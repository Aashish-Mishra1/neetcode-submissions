class Solution {
    public int characterReplacement(String s, int k) {
        HashMap<Character,Integer> freq = new HashMap<>();

        int left = 0,right=0,ans=0,maxf=0;

        while(right<s.length()){
            freq.put(s.charAt(right),freq.getOrDefault(s.charAt(right),0)+1);
            maxf = Math.max(maxf,freq.get(s.charAt(right)));

            while((right-left+1)-maxf>k){
freq.put(s.charAt(left), freq.getOrDefault(s.charAt(left), 0) - 1);

                left++;
            }
            
            ans = Math.max(ans,right-left+1);
            right++;
        }
        return ans;
    }
}
