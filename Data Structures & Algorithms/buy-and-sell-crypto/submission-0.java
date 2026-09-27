class Solution {
    public int maxProfit(int[] prices) {
        
        int ans = 0;
        int mini = prices[0];

        for(int price:prices){
            ans = Math.max(ans,price-mini);
            mini = Math.min(price,mini);
        }
        return ans;
    }
}
