class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> mp = new HashSet<>();

        for (int num : nums) {
            mp.add(num);
        }

        int ans = 0;

        for (int num : nums) {
            if (mp.contains(num - 1) == true)
                continue;

            int count = 0;
            while (mp.contains(num) == true) {
                count++;
                mp.remove(num);
                    num++;
            }
            ans = Math.max(ans, count);
        }

        return ans;
    }
};
