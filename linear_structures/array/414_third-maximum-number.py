# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
414_third-maximum-number LeetCode

Solution: 
    - intuitive
    - set()
    - set() cleaner version !
    - heapq: heapq.heappushpop vs heapq.heapreplace ("heappoppush")
'''

import heapq
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        
        # m1, m2, m3 = nums[0], None, None
        # for i in nums:
        #     if i < m1:
        #         if not m2:
        #             m2 = i
        #         elif i > m2:
        #             m3 = m2
        #             m2 = i
        #         elif i < m2:
        #             if not m3:
        #                 m3 = i    
        #             else:    
        #                 m3 = max(m3, i)    
        #     elif i > m1:
        #         m3 = m2
        #         m2 = m1
        #         m1 = i            
        # if m3 is not None: # explicitly check None instead of using "if m3" because "if 0" returns False !!!
        #     return m3        
        # return m1        
        
        # m = nums[0]
        # s = {m}
        # min_s = m
        # for i in nums:
        #     if len(s) < 3:
        #         s.add(i)
        #         m = max(m, i)
        #         min_s = min(s)
        #     elif i not in s:
        #         if i > min_s:
        #             s.remove(min_s)    
        #             s.add(i)
        #             min_s = min(s)
        # if len(s) < 3:
        #     return m           
        # return min(s)
    
        # maximums = set()
        # for num in nums:
        #     maximums.add(num)
        #     if len(maximums) > 3:
        #         maximums.remove(min(maximums))
        # if len(maximums) == 3:
        #     return min(maximums)
        # return max(maximums)
        
        max_heap = []
        s = set()
        for i in nums:
            if i not in s:
                s.add(i)
                if len(s) > 3:
                    s.remove(heapq.heappushpop(max_heap, i))
                else:
                    heapq.heappush(max_heap, i)
        if len(s) == 3:
            return max_heap[0]   
        return max(s)