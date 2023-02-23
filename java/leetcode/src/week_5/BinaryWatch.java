package week_5;

import java.util.ArrayList;
import java.util.List;

public class BinaryWatch {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> res = new ArrayList<>();
        if (turnedOn > 8) {
            return res;
        }
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (countOnes(i) + countOnes(j) == turnedOn) {
                    // res.add(String.format("%d:%02d", i, j));
                    res.add(convertToTimeStr(i, j));
                }
            }
        }
        return res;
    }

    private int countOnes(int s) {
        int ones = 0;
        for (int i = 0; i < 8; i++) {
            if ((s & (1 << i)) != 0) {
                ones++;
            }
            ;
        }
        return ones;
    }

    private String convertToTimeStr(int a, int b) {
        String p1 = Integer.toString(a);
        String p2 = Integer.toString(b);
        if (p2.length() == 1) {
            p2 = '0' + p2;
        }
        return p1 + ':' + p2;
    }
}
