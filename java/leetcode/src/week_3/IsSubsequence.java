package week_3;

import java.util.ArrayList;

public class IsSubsequence {
    public boolean isSubsequence(String s, String t) {
            // baab 
        // sub: ab
        
        // a 0
        // b     
        // c 
        // d -1
        
        // init hashmap to store indices of letters
        var hm = new ArrayList<ArrayList<Integer>>();
        for (int i=0; i<26; i++) {
            hm.add(new ArrayList<Integer>());
        }
        
        // init int[26] to store pointers for each letter
        int[] ps = new int[26];
        
        // fill hm with list of indices
        for (int j=0; j<t.length(); j++) {
            hm.get(t.charAt(j) - 'a').add(j);
        }
        
        int cur = -1;
        int next = 0;
        for (var c : s.toCharArray()) {
            int k = c - 'a';
            if (ps[k] == hm.get(k).size()) return false; // not found
            next = hm.get(k).get(ps[k]);
            // find next larger index for the letter until the end
            while (next < cur) {
                ps[k]++;
                if (ps[k] == hm.get(k).size()) return false; // not found
                next = hm.get(k).get(ps[k]);
            }
            cur = next;
            ps[k]++;
        }
        return true;
    }

    // public boolean isSubsequence(String s, String t) {
    //     // aebgchac
    //     // sub: acc
    //     int l = 0;
    //     for (var c : s.toCharArray()) {
    //         l = findIn(t, l, c);
    //         if (l == -1) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // private int findIn(String t, int l, char c) {
    //     for (int i=l; i<t.length(); i++) {
    //         if (c == t.charAt(i)) {
    //             return i+1;
    //         }
    //     }
    //     return -1;
    // }
}
