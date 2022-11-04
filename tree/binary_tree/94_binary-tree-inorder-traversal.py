# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
94_binary-tree-inorder-traversal on LeetCode

Solution: 
    - using stack 
    - using stack of tuples
    - (leetcode solution) switch to right child instead of push right child in stack
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # Beginning of walkthrough ==============================
        #     1
        #    / \
        #   2   3   
        #  / \   \
        # 8   4   7
        #    / \
        #   5   6

        # End of walkthrough ====================================

        res = []
        if root:
            stack = [root]
            cur = root
            while cur.left: 
                stack.append(cur.left)
                cur = cur.left
            while stack:
                cur = stack.pop()
                res.append(cur.val)
                if cur.right:
                    stack.append(cur.right)
                    cur_i = cur.right
                    while cur_i.left:
                        stack.append(cur_i.left)
                        cur_i = cur_i.left
        return res

        # res = []
        # if root:
        #     st = [(root, False)]
        #     while st:
        #         cur, visited = st.pop()
        #         while cur.left and not visited:
        #             st.append([cur, True])
        #             cur = cur.left
        #         res.append(cur.val)
        #         if cur.right:
        #             st.append([cur.right, False])
        # return res

        # res = []
        # st = []
        # cur = root
        # while cur or st:
        #     while cur:
        #         st.append(cur)
        #         cur = cur.left
        #     cur = st.pop()
        #     res.append(cur.val)
        #     cur = cur.right
        # return res    