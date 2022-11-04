# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
1089_duplicate-zeros LeetCode

Solution: 
    - with extra O(n) space
    - with extra O(1) space
'''

class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        
        # [1,0,2,3,0,4]
        # [1,0,0,2,3,0]
        
        #shift = []
        #zeros = 0
        #for i in range(len(arr)):
        #    if zeros + i >= len(arr) - 1:
        #        break
        #    shift.append(zeros)  
        #    if arr[i] == 0:
        #        zeros += 1
        #for i in range(len(shift)-1, -1, -1):
        #    if shift[i] == 0:
        #        break
        #    arr[i+shift[i]] = arr[i]
        #i = 0    
        #while i < len(arr)-1:
        #    if arr[i] == 0:
        #        arr[i+1] = 0
        #        i += 2
        #    else:
        #        i += 1
        
        last = 0
        zeros = 0
        l = len(arr)
        for i in range(l):
            if arr[i] == 0:
                zeros += 1
            if zeros + i >= l - 1:
                last = i
                break
        for i in range(last, -1, -1):
            if zeros == 0:
                break
            if arr[i] == 0:
                zeros -= 1
                arr[i+zeros] = 0
                if i+zeros+1 < l:
                    arr[i+zeros+1] = 0
            else:
                arr[i+zeros] = arr[i]