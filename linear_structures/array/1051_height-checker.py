# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
1051_height-checker LeetCode

Solution: 
    - counting sort using int[] or hashmap
'''

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        # Current array : [1,1,4,2,1,2]
        # Target array  : [1,1,1,2,2,4]
        # [0,1,2,3,4,...]
        # [1,2,3,4,5,...]
        # 
        # [3,2,0,1,0,...]
        # [3,5,5,6,0,...]
        # 1 - 0-2 
        # 2 - 3-4 
        # 4 - 5-5 
        hm = [0]*100
        m = 0
        for i in heights:
            hm[i-1] += 1
            m = max(m, i)
        for j in range(1, m):   
            hm[j] += hm[j-1] 
        count = 0    
        for k in range(len(heights)):   
            cur = heights[k]
            if cur == 1:
                if k >= hm[cur-1]:
                    count += 1
            else:
                if k >= hm[cur-1] or k < hm[cur-2]:
                    count += 1
                        
        return count