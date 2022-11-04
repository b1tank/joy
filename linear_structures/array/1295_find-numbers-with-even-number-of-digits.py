# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
1295_find-numbers-with-even-number-of-digits LeetCode

Solution: 
'''

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # Beginning of walkthrough ==============================
        [1,1,0,1,1,1]
        # End of walkthrough ====================================

        def hasEvenDigit(i):
            # si = str(i)
            # 46
            ned = 0
            while i > 0:
                i = (i - i % 10) / 10
                ned += 1
            
            return ned % 2 == 0
        
        res = 0
        for i in nums:
            # check if even-digit
            if hasEvenDigit(i):
                res += 1
        return res         