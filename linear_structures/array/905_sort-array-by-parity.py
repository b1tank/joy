# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
905_sort-array-by-parity LeetCode

Solution: 
    - Two pointers (slow and fast)
    - Two pointers (head and tail - faster and cleaner)
'''
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        # [3,2,1,4,5,7,8]
        # [2,4,8,3,5,7,1]
        # [2,1,3,4]
        # [2,4,1,3]
        
        # i, j = 0, 0
        # while True:
        #     while i < len(A) and A[i] % 2 == 0:
        #         i += 1
        #     j = max(i,j)
        #     while j < len(A) and A[j] % 2 != 0:
        #         j += 1
        #         
        #     if j < len(A):
        #         A[i], A[j] = A[j], A[i]        
        #     else:
        #         return A
        i, j = 0, len(A) - 1
        while i < j:
            if A[i] % 2 > A[j] % 2:
                A[i], A[j] = A[j], A[i]

            if A[i] % 2 == 0: i += 1
            if A[j] % 2 == 1: j -= 1

        return A