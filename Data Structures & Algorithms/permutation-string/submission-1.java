class Solution {
    public boolean checkInclusion(String s1, String s2) {
        
        int[] freq = new int[26];

        for(int i=0;i<s1.length();i++){
            freq[s1.charAt(i)-'a']++;
        }

        int[] rfreq = new int[26];
        int count = s1.length();
        int left = 0;
        for(int i=0;i<s2.length();i++){

            int ind = s2.charAt(i)-'a';
            rfreq[ind]++;
            if(freq[ind]>0) count--;
            if(freq[ind]<rfreq[ind]){
                while(left<=i && freq[ind]<rfreq[ind] ){
                    int ind2 = s2.charAt(left)-'a'; 
                    rfreq[ind2]--;
                    if(freq[ind2]>0) count++;
                    left++;
                }
            }
            // else{
            //     count--;
            // }
            // System.out.println(i);
            // System.out.println(count);
        
            if(count==0) return true;
        }
        return false;
    }
}
