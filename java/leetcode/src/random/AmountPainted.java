package random;

import java.util.Map;
import java.util.TreeMap;

public class AmountPainted {
    public int[] amountPainted(int[][] paint) {
        int n = paint.length;
        int[] res = new int[n];
        TreeMap<Integer, Integer> tm = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            int start = paint[i][0], end = paint[i][1];
            int area = end - start; // initialize

            Map.Entry<Integer, Integer> entry = tm.floorEntry(start);
            // only if the following condition is met, we take a look at the floor entry
            if (entry != null && entry.getValue() >= start) {
                area -= entry.getValue() - start;
                start = entry.getKey();
                if (entry.getValue() >= end) { // update end if necessary
                    end = entry.getValue();
                    area = 0; // area needs to be corrected from negative !
                }
            }

            Map.Entry<Integer, Integer> cur = tm.higherEntry(start);
            while (cur != null && cur.getKey() <= end) {
                area -= Math.min(end, cur.getValue()) - cur.getKey();
                end = Math.max(end, cur.getValue());

                // remove the current entry and move onto the next
                tm.remove(cur.getKey());
                cur = tm.higherEntry(cur.getKey());
            }

            res[i] = area;
            tm.put(start, end);
        }

        return res;
    }
}
