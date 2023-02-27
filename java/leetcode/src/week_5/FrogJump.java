package week_5;

import java.util.HashMap;

public class FrogJump {
    public boolean canCross(int[] stones) {
        // 0 1 2 3 6

        // memo
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        if (stones[1] != 1) {
            return false;
        }

        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i=0; i<stones.length; i++) {
            hm.put(stones[i], i);
        }

        int[][] memo = new int[stones.length][stones.length];
        return canCross(1, 1, stones, hm, memo);
    }
    

    private boolean canCross(int index, int k, int[] stones, HashMap<Integer, Integer> hm, int[][] memo) {
        if (memo[index][k] != 0) {
            return memo[index][k] == 1;
        }

        if (stones[index] + k - 1 <= stones[stones.length-1] && stones[index] + k + 1 >= stones[stones.length-1]) {
            memo[index][k] = 1;
            return true;
        }

        boolean res = false;
        for (int i=k-1; i<=k+1; i++) {
            if (i > 0 && hm.containsKey(stones[index] + i)) {
                boolean tmp = canCross(hm.get(stones[index] + i), i, stones, hm, memo);
                memo[hm.get(stones[index] + i)][i] = tmp ? 1 : 2;
                res |= tmp;
            }
        }

        memo[index][k] = res ? 1 : 2;
        return res;
    }
}