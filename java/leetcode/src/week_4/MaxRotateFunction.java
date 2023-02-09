package week_4;

public class MaxRotateFunction {
    public int maxRotateFunction(int[] nums) {
        // nums: 1 2 3 4 5
        // n: 5
        // max(F(0), F(1), ... F(5))
        // sum: s
        // F(0) 0*a + 1*b + 2*c + 3*d + 4*e
        // F(1) 0*e + 1 a   2 b   3 c   4 d = F(0) + s-n*nums[n-i]
        //      0 d   1 e   2 a   3 b   4 c = F(1) + (s-nums[n-i]) - (n-1)*nums[n-i]
        // F(4) 0 2   1 3   2 4   3 5   4 1

        int s = 0;
        for (int d : nums) {
            s += d;
        }

        int f = 0;
        int n = nums.length;
        for (int i=0; i<n; i++) {
            f += i * nums[i];
        }

        int res = f;
        for (int i=1; i<n; i++) {
            f = f + s - n * nums[n-i];
            res = Math.max(res, f);
        }

        return res;
    }
}