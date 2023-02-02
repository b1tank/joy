package week_3;

import java.util.Stack;

public class DecodeString {
    public String decodeString(String s) {
        // 3[2[a2[xy]c]d]
        // 2[bc]
        Stack<String> stk = new Stack<String>();
        for (var c : s.toCharArray()) {
            if (c != ']') {
                stk.push(Character.toString(c));
            } else {
                var w_str = new StringBuilder();
                while (!stk.peek().equals("[")) {
                    w_str.append(stk.pop());
                }
                stk.pop(); // '['
                var n_str = new StringBuilder();
                while (!stk.empty() && isDigit(stk.peek())) {
                    n_str.append(stk.pop());
                }
                var str = new StringBuilder();
                int k = Integer.parseInt(n_str.reverse().toString());
                for (int i=0; i<k; i++) {
                    str.append(w_str);
                }
                stk.push(str.toString());
           }
        }
        var res = new StringBuilder();
        while (!stk.empty()) {
            res.append(stk.pop());
        }
        return res.reverse().toString();
    }
    private boolean isDigit(String s) {
        if (s.length() != 1) {
            return false;
        }
        return Character.isDigit(s.charAt(0));
    }                    
}