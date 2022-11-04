# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
1299_replace-elements-with-greatest-element-on-right-side LeetCode

Solution: 
'''

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        cur_max = arr[-1]
        arr[-1] = -1
        for i in range(len(arr)-2, -1, -1):
            tmp = arr[i]
            arr[i] = cur_max
            cur_max = max(cur_max, tmp)
        return arr