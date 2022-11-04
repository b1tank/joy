# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
88_merge-sorted-array LeetCode

Solution: 
    - single while loop
    - double iterations but clean
'''

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
                   i     f
        # [1,3,6,7,8,x,x,x]
        # [2,4,5]
               j
                 i     f
        # [1,3,6,7,8,x,x,8]
        # [2,4,5]
               j
               i     f
        # [1,3,6,7,8,x,7,8]
        # [2,4,5]
               j
             i     f
        # [1,3,6,7,8,6,7,8]
        # [2,4,5]
               j
             i   f
        # [1,3,6,7,5,6,7,8]
        # [2,4,5]
             j
           i,flag
        # [1,2,3,4,5,6,7,8]
        # [2,4,5]
          j

        #i, j = m-1, n-1
        #flag = m+n-1
        #while i >= 0 or j >= 0:
        #    if j < 0 or (i >= 0 and nums1[i] > nums2[j]):
        #        nums1[flag] = nums1[i]
        #        i -= 1
        #    else:
        #        nums1[flag] = nums2[j]
        #        j -= 1
        #    flag -= 1

        i, j = m-1, n-1
        flag = m+n-1
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[flag] = nums1[i]
                i -= 1
            else:
                nums1[flag] = nums2[j]
                j -= 1
            flag -= 1
        nums1[:j+1] = nums2[:j+1] # wrong version is nums1[:flag+1] = nums2[:flag+1] !!!