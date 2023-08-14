# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
123_best-time-to-buy-and-sell-stock-iii on LeetCode

Solution: 
    - dp: divide into two sub-problems
    - recursive formula: dp[k, i] = max(dp[k, i-1], dp[k-1, j-1]-prices[j]+prices[i]) where j in [0, i-1]
    - space can be saved by using just a couple of variables
    - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
'''

import sys

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # example: 1 3 2 4 4 7
        dp1, dp2 = 0, 0
        min1, min2 = sys.maxsize, sys.maxsize
        for i in range(len(prices)):
            # compute dp2 before update dp1 because dp2 depends on previous dp1
            dp2 = max(dp2, prices[i] - min2)
            
            # key step: when it's at the '4' before '7', the min2 choices are
            # '132' vs '144' where '13' and '14' are the first transaction, respectively
            # 3 - 1 - 2 = 0 vs 4 - 1 - 4 = -1
            # so the '132' is the better choice and min2 stays at 0 (rather than -1)
            min2 = min(min2, prices[i] - dp1)
            
            dp1 = max(dp1, prices[i] - min1)
            min1 = min(min1, prices[i])
            
            #print('dp2={},min2={},dp1={},min1={}'.format(dp2, min2, dp1, min1))
                        
        return dp2

