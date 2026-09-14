class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        int n = strs.length;

        Map<String,List<String>>mp = new HashMap<>();

        for(String st:strs){
            char[] charArray = st.toCharArray();
            Arrays.sort(charArray);
            String str = new String(charArray);
            if(mp.containsKey(str)==false){
                mp.put(str,new ArrayList<>());
            }
            mp.get(str).add(st);

        }

        return new ArrayList<>(mp.values());
    }
}
