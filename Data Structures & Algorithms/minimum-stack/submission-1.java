class MinStack {
    Stack<Integer> gst;
    Stack<Integer> mst;
    public MinStack() {
        gst = new Stack<>();
        mst = new Stack<>();
    }
    
    public void push(int val) {
        
        gst.push(val);
        

        // push case
        if(mst.isEmpty() || mst.peek()>=val) mst.push(val);

    }
    
    public void pop() {
        // System.out.println(mst.peek());
        // System.out.println(gst.peek());
        if(gst.isEmpty()) return;
        int top = gst.pop();
        
        if(top == mst.peek()) mst.pop();

    }
    
    public int top() {
        
        return gst.peek();
    }
    
    public int getMin() {
        return mst.peek();
    }
}
