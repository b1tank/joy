package week_3;

import java.util.ArrayList;

public class LongestSubstring {
    public int longestSubstring(String s, int k) {
        // aaabbeceeedddd 3
        if (s.isEmpty()) {
            return 0;   
        }
        int[] hm = new int[26];
        for (char c : s.toCharArray()) {
            hm[c-'a']++;
        }
        ArrayList<String> ls = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (hm[c-'a'] >= k) {
                sb.append(c);
            } else {
                if (sb.length() > 0) {
                    ls.add(sb.toString());
                    sb.setLength(0);
                }
            }
        }
        if (sb.length() == s.length()) {
            return s.length();
        } else {
            ls.add(sb.toString());
        }

        int res = 0;
        for (String str : ls) {
            System.out.println(str);
            res = Math.max(res, longestSubstring(str, k));
        }
        
        return res;
    }
}
