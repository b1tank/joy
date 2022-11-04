# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
283_move-zeros LeetCode

Solution: 
'''

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i = 0
        while i < len(nums):
            if nums[i] != 0:
                i += 1
            else:
                break    
        j = i        
        while j < len(nums):
            if nums[j] != 0:
                if nums[i] != nums[j]:
                    nums[i] = nums[j]    
                i += 1
            j += 1
        for k in range(i, len(nums)):
            nums[k] = 0