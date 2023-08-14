# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
117_populating-next-right-pointers-in-each-node-ii on LeetCode

Solution: 
    - BFS: deque (exactly the same code as 116)
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

        if root:
            cur = root
            next_level = root
            level_update = True
            while cur.next or (next_level and level_update):
                if cur.next:
                    cur = cur.next
                elif next_level:
                    cur = next_level
                    level_update = False
                    
                if cur.left or cur.right:
                    if not level_update:
                        level_update = True
                        if cur.left:
                            next_level = cur.left
                        else:
                            next_level = cur.right
                    if cur.left and cur.right:
                        cur.left.next = cur.right
                        source = cur.right 
                    elif cur.left:
                        source = cur.left 
                    elif cur.right:
                        source = cur.right 
                else:
                    continue
                    
                target = cur.next
                while target:
                    if target.left:
                        source.next = target.left
                        break
                    elif target.right:
                        source.next = target.right
                        break
                    target = target.next
                        
        return root