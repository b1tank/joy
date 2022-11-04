# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
250_count-univalue-subtrees on LeetCode

Solution: 
    - recursive: bottom-up
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
          3   1   
         / \ / \
        2  4 4  2
        # End of walkthrough ====================================

    def isUnival(self, root: TreeNode) -> bool:
        if root:
            res = True
            if root.left:
                res = res and self.isUnival(root.left) and root.val == root.left.val  
            if root.right:    
                res = res and self.isUnival(root.right) and root.val == root.right.val
            return res
        return True
    def countUnivalSubtrees(self, root: TreeNode) -> int:
        if root:
            count = 0
            if self.isUnival(root):
                count += 1
            return count + self.countUnivalSubtrees(root.left) + self.countUnivalSubtrees(root.right)
        return 0
        