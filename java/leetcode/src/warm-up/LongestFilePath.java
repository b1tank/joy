import java.util.Stack;

public class LongestFilePath {
    public int lengthLongestPath(String input) {
        // dir 
        //     nt sub1
        //     ntt     ff.1
        //     nt f.2
        //     nt sub2
        //     ntt       sub3
        //     nttt           f.3    
        int tc0 = -1;
        int tc1 = 0;
        String cur = "";
        Boolean isFile = false;
        Stack<String> st = new Stack<>();
        int m = 0;
        
        input += '\n';
        for (int i=0; i<input.length(); i++) {
            if (input.charAt(i) == '\t') {
                tc1++;
            } else if (input.charAt(i) != '\n') {
                cur += input.charAt(i);
                if (input.charAt(i) == '.') {
                    isFile = true;
                }
            } else {
                if (tc1 > tc0) {
                   st.push(cur);
                } else {
                    for (int j=0; j<tc0-tc1+1; j++) {
                        st.pop();
                    }
                    st.push(cur);
                }
                    
                if (isFile) {
                    m = Math.max(m, String.join("/", st).length());
                }
                
                // reset
                tc0 = tc1;
                tc1 = 0;
                cur = "";
                isFile = false;
            }
        }
        return m;
    }
}
