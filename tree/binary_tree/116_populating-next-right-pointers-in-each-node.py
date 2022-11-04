# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
116_populating-next-right-pointers-in-each-node on LeetCode

Solution: 
    - BFS: deque 
    - constant space: build bridge using next pointer
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

from collections import deque

class Solution:
    def connect(self, root: 'Node') -> 'Node':

        # Beginning of walkthrough ==============================

        # End of walkthrough ====================================
        
        # if root:
        #     q = deque([root])
        #     while q:
        #         l = len(q)
        #         for i in range(l):
        #             cur = q.popleft()
        #             if i < l - 1:
        #                 cur.next = q[0]
        #             if cur.left:
        #                 q.append(cur.left)
        #             if cur.right:
        #                 q.append(cur.right)
        # return root

        if root and root.left:
            cur = root
            next_level = root
            # traversing the tree nodes using next pointer or next_level leading node
            while cur.next or (next_level and next_level.left):
                if cur.next:
                    cur = cur.next
                elif next_level:
                    cur = next_level
                    next_level = cur.left # update next_level leading node
                cur.left.next = cur.right
                if cur.next:
                    cur.right.next = cur.next.left
        return root