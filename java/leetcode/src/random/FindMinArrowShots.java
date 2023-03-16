package random;

import java.util.Arrays;

class FindMinArrowShots {
    public int findMinArrowShots(int[][] points) {
        // Arrays.sort(points, (a, b) -> (a[0] < b[0] ? -1 : (a[0] == b[0] ? 0 : 1))); // avoid integer overflow
        Arrays.sort(points, (a, b) -> Integer.valueOf(a[0]).compareTo(b[0])); // avoid integer overflow
        // Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0])); // avoid integer overflow
        // Arrays.sort(points, Comparator.comparingInt(a -> a[0])); // avoid integer overflow
        // Arrays.sort(points, (a, b) -> {
        //    if (a[0] == b[0]) return 0;
        //    if (a[0] < b[0]) return -1;
        //    return 1;
        // });
        int res = 0;
        int tail = Integer.MIN_VALUE;
        for (int i=0; i<points.length; i++) {
            if (i > 0 && points[i][0] <= tail) {
                tail = Math.min(tail, points[i][1]);
            } else {
                res++;
                tail = points[i][1];
            }
        }
        return res;
    }
}