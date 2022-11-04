# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
105_construct-binary-tree-from-preorder-and-inorder-traversal on LeetCode

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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:

        # Beginning of walkthrough ==============================

        # End of walkthrough ====================================
        if inorder:
            root = TreeNode(preorder[0])
            ri = inorder.index(preorder[0])
            root.left = self.buildTree(preorder[1:ri+1], inorder[:ri])
            root.right = self.buildTree(preorder[ri+2:], inorder[ri:])
            return root
        return None