# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
26_remove-duplicates-from-sorted-array LeetCode

Solution: 
'''

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # [0,0]
        
        i, j = 0, 0
        while j < len(nums):
            if nums[i] != nums[j]:
                nums[i+1] = nums[j]
                i += 1
            j += 1
        return i+1