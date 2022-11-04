# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
977_squares-of-a-sorted-array LeetCode

Solution: 
    - firstly complete common-case logic and deal with corner-case afterwards in case corner-cases are already taken care of by common-case logic
        e.g. common case: both negatives and positives [-4,2,4]
             edge cases: all positives or negatives [0,2,4], [-9,-4,-1] or with zero [-3,0,1,2]
    - Two pointers (head and tail)
'''

class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        # Beginning of walkthrough ==============================
        [1,1,0,1,1,1]
        # End of walkthrough ====================================

        res = []
        i = 0
        while i < len(A)-1 and A[i] < 0:
            i += 1
        left, right = i-1, i    
        while left >= 0 and right < len(A):
            l_sq = A[left]**2
            r_sq = A[right]**2
            if l_sq < r_sq:
                res.append(l_sq)
                left -= 1
            else:
                res.append(r_sq)
                right += 1
        if left >= 0:        
            for i in range(left,-1,-1):
                res.append(A[i]**2)
        if right < len(A):        
            for i in range(right,len(A)):
                res.append(A[i]**2)
                
        return res
        
        # left = 0
        # right = len(A) - 1
        # res = []
        # while left <= right:
        #     l_sq = A[left]**2
        #     r_sq = A[right]**2
        #     if l_sq > r_sq:
        #         res.append(l_sq)
        #         left += 1
        #     else:
        #         res.append(r_sq)
        #         right -= 1
        # return res[::-1]