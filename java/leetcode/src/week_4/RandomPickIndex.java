package week_4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Random;

class RandomPickIndex {
    private HashMap<Integer, List<Integer>> hm;
    private Random rm;

    public RandomPickIndex(int[] nums) {
        this.hm = new HashMap<Integer, List<Integer>>();
        for (int i=0; i<nums.length; i++) {
            if (this.hm.containsKey(nums[i])) {
                this.hm.get(nums[i]).add(i);
            } else {
                this.hm.put(nums[i], new ArrayList<>(Arrays.asList(i)));
            }
        }
        this.rm = new Random();
    }
    
    public int pick(int target) {
        List<Integer> indices = hm.get(target);
        return indices.get(rm.nextInt(indices.size()));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */