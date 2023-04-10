package random;

public class MaximumRemovals {
    // lesson from this problem:
    // the intuitive approach I firstly came up with is to use linked list to optimize deletion process (O(N)) and use brutal force to check subsequence requirement (O(N^2))
    // so the brutal force complexity is O(N + N^2)
    // then I tried so hard to think of how to optimize the O(N^2) part, but could not figure out how to reduce complexity of checking subsequence requirement from O(N) to O(logN) or O(1) - and thus I got stuck !!!
    // after reading the top voted solution, I realize that I should've looked at optimizing the "other N" (i.e. removable array scanning) in the O(N^2) complexity after I got stuck at optimizing the "first N" (i.e. subsequence checking)!
    // it turned out that removable array scanning can be easily optimized from O(N) to O(logN) via binary search, which is easy to figure out by itself!
    // then the linked list deletion optimization is actually no more necessary because the complexity can be O(NlogN) + O(NlogN) or O((N+N)logN) = O(NlogN)

    // the biggest takeaway is that when one "N" in a O(N^2) complexity is not optimizable, try the other one !!!!!!!!!!!!!
    public int maximumRemovals(String s, String p, int[] removable) {
        int left = 0, right = removable.length;
        StringBuilder sb = new StringBuilder(s);
        while (left < right) {
            int mid = left + (right - left) / 2;
            for (int i=0; i<=mid; i++) {
                sb.setCharAt(removable[i], '/');
            }

            if (isSubSeq(p, sb)) {
                left = mid + 1;
            } else {
                right = mid;
            }

            for (int i=0; i<=mid; i++) {
                sb.setCharAt(removable[i], s.charAt(removable[i]));
            }
        }

        return left;
    }

    private boolean isSubSeq(String p, StringBuilder sb) {
        int p1 = 0, p2 = 0;
        while (p2 != p.length()) {
            if (p1 == sb.length()) return false;
            if (p.charAt(p2) == sb.charAt(p1)) {
                p1++;
                p2++;
            } else {
                p1++;
            }
        }

        return true;
    }
}