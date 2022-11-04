# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
102_binary_tree_level_order_traversal on LeetCode

Solution: 
    - BFS using deque
'''

from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:

        # Beginning of walkthrough ==============================
            1
           / \
          2   3   
         / \   \
        8   4   7
           / \
          5   6

            1
           / \
          2   3   
             / \
            4   7
        # End of walkthrough ====================================

        res = []
        if root:
            q = deque([root])
            while q:
                l = []
                length = len(q)
                for i in range(length):
                    cur = q.popleft()
                    l.append(cur.val)
                    if cur.left:
                        q.append(cur.left)
                    if cur.right:
                        q.append(cur.right)
                res.append(l)
        return res