package week_5;

import java.util.Stack;

public class RemoveKDigits {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();

        for (int i=0; i<num.length(); i++) {
            while (k > 0 && !st.empty() && st.peek() > num.charAt(i)) {
                st.pop();
                k--;
            }

            st.push(num.charAt(i));
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        StringBuilder sb = new StringBuilder();
        while (!st.empty()) {
            sb.append(st.pop());
        }

        while (sb.length() > 0 && sb.charAt(sb.length()-1) == '0') {
            sb.deleteCharAt(sb.length()-1);
        }

        sb.reverse();

        return sb.length() == 0 ? "0" : sb.toString();
    }
}