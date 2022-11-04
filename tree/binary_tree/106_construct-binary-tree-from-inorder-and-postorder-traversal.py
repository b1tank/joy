# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
106_construct-binary-tree-from-inorder-and-postorder-traversal on LeetCode

Solution: 
    - recursive: top-down
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:

        # Beginning of walkthrough ==============================

        # End of walkthrough ====================================
        if inorder:
            root = TreeNode(postorder[-1])
            ri = inorder.index(postorder[-1])
            root.left = self.buildTree(inorder[:ri], postorder[:ri])
            root.right = self.buildTree(inorder[ri+1:], postorder[ri:-1])
            return root
        return None