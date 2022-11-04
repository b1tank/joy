# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
112_path-sum on LeetCode

Solution: 
    - recursive: top-down
    - iterative
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:

        # Beginning of walkthrough ==============================
            1
            / \
        3   1   
        / \ / \
        2  4 4  2
        # End of walkthrough ====================================

        # if root:
        #     if root.left and self.hasPathSum(root.left, sum - root.val) or (root.right and self.hasPathSum(root.right, sum - root.val)):
        #         return True
        #     return root.left is None and root.right is None and root.val == sum
        # return False

        if root:
            st = [(root, root.val)]
            while st:
                cur_node, cur_sum = st.pop()
                if cur_node.left:
                    st.append((cur_node.left, cur_sum + cur_node.left.val))
                if cur_node.right:
                    st.append((cur_node.right, cur_sum + cur_node.right.val))
                if cur_node.left is None and cur_node.right is None and cur_sum == sum:
                    return True
        return False