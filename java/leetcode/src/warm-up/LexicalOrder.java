import java.util.ArrayList;
import java.util.List;

public class LexicalOrder {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        int cur = 1;
        // 432 44 5 50 51
        // 10
        // 13
        // 192 corner case: 
        for (int i = 0; i < n; i++) {
            res.add(cur);
            if (cur * 10 <= n) { // first step that is easiest to come up with
                cur *= 10;
            } else if (cur % 10 != 9 && cur < n) { // don't forget cur < n
                cur++;
            } else {
                // this final single else block results actually from combining 2 blocks
                // 
                // } else if (cur == n) {
                //     cur /= 10; // this is just special treatment for cur == n, so it can be merged into the block below
                //     cur++; // this line and the following while block are the same as the one below, so they can be shared
                //     while (cur % 10 == 0) {
                //         cur /= 10;
                //     }
                // } else if (cur % 10 == 9) {
                //     cur++;
                //     while (cur % 10 == 0) {
                //         cur /= 10;
                //     }
                // }
                
                if (cur == n) cur /= 10; // for corner case e.g. 192
                cur++;
                while (cur % 10 == 0) {
                    cur /= 10;
                }
            }
        }
        return res;
    }
}
