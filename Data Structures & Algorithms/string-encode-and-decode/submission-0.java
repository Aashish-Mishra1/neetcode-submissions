class Solution {

    public String encode(List<String> strs) {

        StringBuilder st = new StringBuilder();

        for(String s:strs){
            int len = s.length();
            st.append(len);
            st.append('#');
            st.append(s);
        }
        // System.out.println(st);
        return st.toString();
        

    }

    public List<String> decode(String str) {

        int i=0;
        List<String> ans = new ArrayList<String>();
        
        while(i<str.length()){

            int count = 0;
            while(i<str.length() && str.charAt(i)!='#'){
                count++;
                i++;
            }

            int len = Integer.parseInt(str.substring(i-count,i));
            ans.add(str.substring(i+1,i+1+len));

            i += len+1;
        }
        return ans;

    }
}
