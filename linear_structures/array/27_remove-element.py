# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
27_remove-element LeetCode

Solution: 
'''

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        count = 0
        for i in nums:
            if i != val:
                count += 1
        p = count        
        for i in range(count):
            if nums[i] == val:
                # find the next value which is not equal to val
                while nums[p] == val:
                    p += 1
                # swap values at i and p
                tmp = nums[i]    
                nums[i] = nums[p]
                nums[p] = tmp
                p += 1
        return count        