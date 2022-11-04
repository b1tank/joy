# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
1_two-sum LeetCode

Solution: 
'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        hm = {}
        for i in range(len(nums)):
            if target-nums[i] in hm:
                return [i, hm[target-nums[i]]]
            hm[nums[i]] = i