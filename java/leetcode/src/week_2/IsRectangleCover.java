package week_2;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class IsRectangleCover {
    public boolean isRectangleCover(int[][] rectangles) {
        int min_x = Integer.MAX_VALUE;
        int min_y = Integer.MAX_VALUE;
        int max_a = Integer.MIN_VALUE;
        int max_b = Integer.MIN_VALUE;
        
        for (int i=0; i<rectangles.length; i++) {
            min_x = Math.min(min_x, rectangles[i][0]);
            min_y = Math.min(min_y, rectangles[i][1]);
            max_a = Math.max(max_a, rectangles[i][2]);
            max_b = Math.max(max_b, rectangles[i][3]);
        }
        
        Arrays.sort(rectangles, new XyComparator());

        PriorityQueue<int[]> heap = new PriorityQueue<int[]>(rectangles.length, new XyComparator());
        heap.add(new int[]{min_x, min_y, max_b});

        for (int i=0; i<rectangles.length; i++)
        {
            int[] slot = heap.poll();
            while (!heap.isEmpty() && heap.peek()[0] == slot[0] && heap.peek()[1] == slot[2]) {
                slot = mergeSlots(slot, heap.poll());
            }
            if (!checkFit(slot, rectangles[i], max_a)) {
                return false;
            }
            heap.add(new int[]{rectangles[i][2], rectangles[i][1], rectangles[i][3]});
            if (slot[2] > rectangles[i][3]) {
                heap.add(new int[]{slot[0], rectangles[i][3], slot[2]});
            }
        }
        
        int[] slot = heap.poll();
        while (!heap.isEmpty() && heap.peek()[0] == slot[0] && heap.peek()[1] == slot[2]) {
            slot = mergeSlots(slot, heap.poll());
        }
        return slot[0] == max_a && slot[1] == min_y && slot[2] == max_b;
    }
    
    static class XyComparator implements Comparator<int[]> {
        public int compare(int[] s1, int[] s2) {
            if (s1[0] > s2[0]) {
                return 1;
            } else if (s1[0] < s2[0]) {
                return -1;
            } else {
                if (s1[1] > s2[1]) {
                    return 1;
                } else if (s1[1] < s2[1]) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }
    
    private int[] mergeSlots(int[] slot_low, int[] slot_high) {
        return new int[] {slot_low[0], slot_low[1], slot_high[2]};
    }
    
    private boolean checkFit(int[] slot, int[] rectangle, int max_a) {
        return slot[0] == rectangle[0] && slot[1] == rectangle[1] && slot[2] >= rectangle[3] && rectangle[2] <= max_a;
    }
}