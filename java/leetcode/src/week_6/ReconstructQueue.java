package week_6;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class ReconstructQueue {
    public int[][] reconstructQueue_official(int[][] people) {
        Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);

        List<int[]> ordered = new LinkedList<>();
        for (int[] p : people)
            ordered.add(p[1], p);

        return ordered.toArray(new int[people.length][2]);
    }

    public int[][] reconstructQueue(int[][] people) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(new CustomComparator());
        int n = people.length;
        int[][] res = new int[n][2];
        for (int i = 0; i < n; i++) {
            pq.offer(people[i]);
        }

        LinkedList<int[]> ll = new LinkedList<>();
        while (!pq.isEmpty()) {
            insertToQueue(ll, pq.poll());
        }

        for (int i = 0; i < ll.size(); i++) {
            res[i][0] = ll.get(i)[0];
            res[i][1] = ll.get(i)[1];
        }

        return res;
    }

    private void insertToQueue(LinkedList<int[]> q, int[] item) {
        if (q.isEmpty()) {
            q.add(item);
            return;
        } else {
            int count = item[1];
            for (int i = 0; i < q.size(); i++) {
                if (count == 0) {
                    q.add(i, item);
                    return;
                }

                int[] cur = q.get(i);
                if (cur[0] >= item[0]) {
                    count--;
                }
            }

            q.add(item);
        }
    }

    private class CustomComparator implements Comparator<int[]> {
        public int compare(int[] a1, int[] a2) {
            if (a1[0] > a2[0]) {
                return -1;
            } else if (a1[0] < a2[0]) {
                return 1;
            } else {
                if (a1[1] > a2[1]) {
                    return 1;
                } else if (a1[1] < a2[1]) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }
}