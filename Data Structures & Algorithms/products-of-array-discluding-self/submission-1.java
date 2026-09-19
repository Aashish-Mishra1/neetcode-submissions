class Solution {
    public int[] productExceptSelf(int[] nums) {
        
        int n = nums.length;
        int[] prd = new int[n];
        prd[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            prd[i] = nums[i] * prd[i+1];
        }
        // for(int it:prd) System.out.println(it);

        int temp = 1;
        for(int i=0;i<n;i++){
            int x = nums[i];
            nums[i] = temp * (i+1<n?prd[i+1]:1);
            temp *= x;
        }
        return nums;
    }
}  
