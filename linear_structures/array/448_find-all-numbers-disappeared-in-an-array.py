# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
448_find-all-numbers-disappeared-in-an-array LeetCode

Solution: 
    - sort by using swap to find the right position for each element (similar to 41_first-missing-positive)
        explanation of O(n): 
            - The while loop condition evaluates to true at-most 'n' times across all iterations of the outer for loop because each number is visited once and swapped to the right place at most once
    - use negative marking (use index as hash key and sign as hash value which is PRESENCE detector)
'''

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # [4,3,1,3]
        # [3,3,1,4]
        # [1,3,3,4]
        for i in range(len(nums)):
            while nums[nums[i]-1] != nums[i]:
                nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        return [i+1 for i in range(len(nums)) if nums[i] != i+1]        

        #for i in nums:
        #    if nums[abs(i)-1] > 0:
        #        nums[abs(i)-1] = -nums[abs(i)-1]
        #return [i+1 for i in range(len(nums)) if nums[i] > 0]        