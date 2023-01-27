package week_2;

public class FindTheDifference {
    public char findTheDifference(String s, String t) {
        char res = t.charAt(s.length());
        for (int i=0; i<s.length(); i++) {
            res ^= s.charAt(i);
        }
        for (int i=0; i<s.length(); i++) {
            res ^= t.charAt(i);
        }
        return res;
    }
}
