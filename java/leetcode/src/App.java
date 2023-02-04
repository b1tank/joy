import week_2.*;
import week_3.DecodeString;
import week_3.LongestSubstring;

public class App {
    public static void main(String[] args) throws Exception {
        var s = "aaabeceeedddd";
        var cla = new LongestSubstring();
        var res = cla.longestSubstring(s, 3);
        System.out.println(res);
    }
}
