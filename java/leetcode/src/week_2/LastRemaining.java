package week_2;

public class LastRemaining {
    public int lastRemaining(int n) {
        // 1 2 3 4 5  6  7  8  9 10 11 12 13 14 15 16
        // 2 4 6  8  10 12 14 16
        // 6 10 14 4
        // 6 14 8
        // 6   
        //
        // 1 2 3 4 5  6  7  8  9 10 11 12 13 
        // 2 4 6  8  10 12
        // 2 6 10    
        // 6    
        //     1>13 1
        //     2<12 2
        //     2>10 4
        //     6 6
               
        int l = 1;
        int r = n;     
        int step = 1;
        boolean toRight = true;
        while (l < r) {
            if (toRight) {
                if ((r-l) % (2*step) == 0) {
                    r = r - step;
                }
                l = l + step;
            } else {
                if ((r-l) % (2*step) == 0) {
                    l = l + step;
                }
                r = r - step;
            }
            
            step *= 2;
            toRight = !toRight;
        }
        return l; 
    }
}
