package week_6;

public class ToHex {
    public String toHex(int num) {
        StringBuilder sb = new StringBuilder();
        int mask = 0xf;
        int tmp = 0;
        boolean hasNonZero = false;
        for (int i=7; i>=0; i--) {
            tmp = num >>> (i*4); // we can use either >> or >>> here since the mask will ignore those emerged '0' or '1' during shifting
            tmp &= mask;
            if (tmp != 0) {
                hasNonZero = true;
            }
            if (hasNonZero) {
                sb.append(toHexChar(tmp));
            }
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }

    private char toHexChar(int n) {
        if (n < 10) {
            return (char) ('0' + n); // if use "(char) n", it return '\u0001'
        }
        return (char) ('a' + n - 10);
    }
}