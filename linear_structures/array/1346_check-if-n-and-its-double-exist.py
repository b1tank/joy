# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
1346_check-if-n-and-its-double-exist LeetCode

Solution: 
'''

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        hm = set()
        for i in arr:
            if i in hm:
                return True
            hm.add(i*2)
            if i % 2 == 0:
                hm.add(i/2)
        return False        