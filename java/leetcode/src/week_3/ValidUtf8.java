package week_3;

public class ValidUtf8 {
    public boolean validUtf8(int[] data) {
        // 0xx
        // 110xxxxx 10xx 10xx
        // 1110xx 10   10
        // 11110x 10   10
        
        // 11000101 10000010 00000001
        int left10 = 0;
        for (int i=0; i<data.length; i++) {
            if (left10 == 0) {
                if (((data[i] >> 5) ^ 1) == 0b00000111) { // leftmost are 110
                    left10 = 1;
                } else if (((data[i] >> 4) ^ 1) == 0b00001111) { // leftmost are 1110
                    left10 = 2;
                } else if (((data[i] >> 3) ^ 1) == 0b00011111) { // leftmost are 11110
                    left10 = 3;
                } else if (((data[i] >> 7) | 0) != 0) { // check if leftmost bit is 0
                    return false;
                }
            } else {
                left10--;
                if (((data[i] >> 6) ^ 1) != 0b00000011) { // check if leftmost is 10
                    return false;
                }
            }
        } 
        return left10 == 0;
    }
}
