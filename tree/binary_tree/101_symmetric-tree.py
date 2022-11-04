# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
101_symmetric-tree on LeetCode

Solution: 
    - recursive: bottom-up
    - iterative: double stacks
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # Beginning of walkthrough ==============================
         1
        / \
       3   3   
      / \ / \
     2  4 4  2
    # End of walkthrough ====================================

    # def isFlipped(self, r1, r2) -> bool:
    #     if r1 is None:
    #         return r2 is None
    #     elif r2 is None:
    #         return False
    #     else:
    #          return r1.val == r2.val and self.isFlipped(r1.left, r2.right) and self.isFlipped(r1.right, r2.left)
    # def isSymmetric(self, root: TreeNode) -> bool:
    #     if root:
    #         return self.isFlipped(root.left, root.right)
    #     return True

    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        s1 = [root.left]
        s2 = [root.right]
        while s1 and s2:
            cur1 = s1.pop()
            cur2 = s2.pop()
            if cur1 is None and cur2 is None:
                continue
            elif (cur1 is not None and cur2 is None) or (cur1 is None and cur2 is not None):
                return False
            elif cur1.val == cur2.val:
                if cur1.left:
                    s1.append(cur1.left)
                if cur1.right:
                    s1.append(cur1.right)
                if cur2.right:
                    s2.append(cur2.right)
                if cur2.left:
                    s2.append(cur2.left)
            else:
                return False
        return True