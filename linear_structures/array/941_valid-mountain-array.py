# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
941_valid-mountain-array LeetCode

Solution: 
    - one pass with corner case checks
    - one pass (clean)
'''

class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        # [1,2,1]
        if len(A) < 3:
            return False
        if A[1] <= A[0] or A[-1] >= A[-2]:
            return False
        up = True
        for i in range(2,len(A)):
            if up: 
                if A[i] == A[i-1]:
                    return False
                if A[i] < A[i-1]:
                    up = False
            else:
                if A[i] >= A[i-1]:
                    return False
        return not up            
    
        # N = len(A)
        # i = 0
        
        # # walk up
        # while i+1 < N and A[i] < A[i+1]:
        #     i += 1
        
        # # peak can't be first or last
        # if i == 0 or i == N-1:
        #     return False
        
        # # walk down
        # while i+1 < N and A[i] > A[i+1]:
        #     i += 1
        
        # return i == N-1