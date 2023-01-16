public class FirstUniqChar {
    public int firstUniqChar(String s) {
        // letlcode
        int[] hm = new int[26];
        for (int i=0; i<s.length(); i++) {
            if (hm[s.charAt(i) - 'a'] < 2) 
                hm[s.charAt(i) - 'a']++;
        }
        for (int i=0; i<s.length(); i++) {
            if (hm[s.charAt(i) - 'a'] == 1) 
                return i;
        }
        return -1;
    }
}
