# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
41_first-missing-positive LeetCode

Solution: 
    - sort by using swap to find the right position for each element (similar to 448_find-all-numbers-disappeared-in-an-array)
        explanation of O(n): 
            - The while loop condition evaluates to true at-most 'n' times across all iterations of the outer for loop because each number is visited once and swapped to the right place at most once
    - use negative marking (use index as hash key and sign as hash value which is PRESENCE detector)
        explanation: https://leetcode.com/problems/first-missing-positive/solution/
'''

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        
        for i in range(len(nums)):
            while nums[i]-1 < len(nums) and nums[i]-1 >= 0 and nums[nums[i]-1] != nums[i]:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        res = 1
        for n in nums:
            if n == res:
                res += 1
            else:
                break
        return res