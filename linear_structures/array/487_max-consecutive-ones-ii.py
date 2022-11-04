# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
487_max-consecutive-ones-ii LeetCode

Solution: 
    - split batches of ones by a single zero
        e.g. [1,1,0,0,1,0,1,1,1]
        [1,1] - 0 - [] - 0 - [1] - 0 - [1,1,1]
'''

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        # [1,0,1,1,0,0,1]
        m = 0
        last_batch = -1 # to take care of arrays starting with 1
        cur_batch = 0
        for i in nums:
            if i == 1:
                cur_batch += 1
                m = max(m, cur_batch+last_batch+1)
            else:
                last_batch = cur_batch   
                cur_batch = 0
        return max(m, cur_batch+last_batch+1)