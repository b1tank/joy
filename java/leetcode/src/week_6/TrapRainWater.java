package week_6;

import java.util.PriorityQueue;

public class TrapRainWater {
    public int trapRainWater(int[][] heightMap) {
        // https://leetcode.com/problems/trapping-rain-water-ii/solutions/89495/how-to-get-the-solution-to-2-d-trapping-rain-water-problem-from-1-d-case/?orderBy=most_votes
        // 1 3 4 1 2 1
        // 3 2 1 5 1 2
        // 2 4 3 2 4 4
        int m = heightMap.length;
        int n = heightMap[0].length;
        int res = 0;
        
        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        for (int i=0; i<n; i++) {
            minHeap.offer(new int[]{0, i, heightMap[0][i]});
            minHeap.offer(new int[]{m-1, i, heightMap[m-1][i]});
            visited[0][i] = true;
            visited[m-1][i] = true;
        }

        for (int j=1; j<m-1; j++) {
            minHeap.offer(new int[]{j, 0, heightMap[j][0]});
            minHeap.offer(new int[]{j, n-1, heightMap[j][n-1]});
            visited[j][0] = true;
            visited[j][n-1] = true;
        }

        int[][] dirs = new int[][]{{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!minHeap.isEmpty()) {
            int[] cur = minHeap.poll();

            for (int[] dir : dirs) {
                int x = cur[0] + dir[0];
                int y = cur[1] + dir[1];
                if (x > m-1 || x < 0 || y > n-1 || y < 0 || visited[x][y] == true) {
                    continue;
                }
                minHeap.offer(new int[]{x, y, Math.max(heightMap[x][y], cur[2])});
                if (heightMap[x][y] < cur[2]) {
                    res += cur[2] - heightMap[x][y];
                }
                visited[x][y] = true;
            }
        }

        return res;
    }
}
