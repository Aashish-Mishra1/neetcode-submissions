class Solution {
    public int evalRPN(String[] tokens) {
        
        Stack<Integer> st = new Stack<>();

        for(String s:tokens){
            char ch = s.charAt(0);
            int len = s.length();
            if(ch=='+' && len==1){
                int x = st.peek();
                st.pop();
                int y = st.peek();
                st.pop();
                st.push(x+y);
            }
            else if(ch=='-' && len==1){
                int x = st.peek();
                st.pop();
                int y = st.peek();
                st.pop();
                st.push(y-x);
            }
            else if(ch=='*' && len==1){
                int x = st.peek();
                st.pop();
                int y = st.peek();
                st.pop();
                st.push(x*y);
            }
            else if(ch=='/' && len==1){
                int x = st.peek();
                st.pop();
                int y = st.peek();
                st.pop();
                st.push(y/x);
            }
            else{
                // System.out.println(s.charAt(0)-'0');
                // System.out.println(s.charAt(0));
                int num = Integer.parseInt(s);
                st.push(num);
            }
        }

        return st.peek();
    }
    
}
