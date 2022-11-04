# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
485_max-consecutive-ones LeetCode

Solution: 
    - final check
'''

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # Beginning of walkthrough ==============================
        [1,1,0,1,1,1]
        # End of walkthrough ====================================

        res, count = 0, 0
        for i in nums:
            if i == 1:
                count += 1
            else:    
                res = max(res, count) # has to be ahead of count=0
                count = 0
        
        return max(res, count) # final count has to be examined !