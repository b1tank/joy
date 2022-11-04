# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
104_maximum-depth-of-binary-tree on LeetCode

Solution: 
    - recursive: bottom-up
    - iterative: BFS using deque
    - iterative: stack of tuple(TreeNode, Depth)
'''

from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:

        # Beginning of walkthrough ==============================
            1
           / \
          2   3   
           \   \
            4   7
             \
              6
        # End of walkthrough ====================================

        # if root:
        #     return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
        # return 0

        # if root:
        #     q = deque([root])
        #     level = 0
        #     while q:
        #         level += 1
        #         length = len(q)
        #         for i in range(length):
        #             cur = q.popleft()
        #             if cur.left:
        #                 q.append(cur.left)
        #             if cur.right:
        #                 q.append(cur.right)
        #     return level
        # return 0

        if root:
            st = [(1, root)]
            max_depth = 1
            while st:
                cur_depth, cur = st.pop()
                max_depth = max(max_depth, cur_depth)
                if cur.left:
                    st.append((cur_depth + 1, cur.left))
                if cur.right:
                    st.append((cur_depth + 1, cur.right))
            return max_depth
        return 0