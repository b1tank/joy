package week_7;

public class SplitArray {
    public int splitArray(int[] nums, int k) {
        // 7 2 5 |10| 8
        // 7 9 14 24 32
        // 32  25  23  18  8
        // dp[0][k]
        // dp[i][j] = min(max(dp[a]][j-1], sum[i..a-1]), a=i+1..n-(j-1)) i=0..n-1 j=1..k
        int n = nums.length;
    
        // right sums
        int[] sums_r = new int[n];
        sums_r[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--) {
            sums_r[i] = sums_r[i+1] + nums[i];
        }
        
        // dp init
        int[][] dp = new int[n][k+1];
        for (int i=0; i<n; i++) {
            dp[i][1] = sums_r[i];
        }
        
        // fill dp
        for (int j=2; j<=k; j++) {
            for (int i=n-1; i>=0; i--) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int a=i+1; a<=n-j+1; a++) {
                    if (a < n) { // check index boundary
                        dp[i][j] = Math.min(dp[i][j], Math.max(dp[a][j-1], sums_r[i]-sums_r[a]));
                    }
                }
            }
        } 
        
        return dp[0][k];
    }
}