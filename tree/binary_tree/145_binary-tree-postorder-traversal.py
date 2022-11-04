# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
binary_tree_postorder_traversal on LeetCode

Solution: 
    - iterative
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:

        # Beginning of walkthrough ==============================
            4
           / \
          2   6
         / \ / \
        1  3 5  7

        cur 4; stack [4];
        cur 2; stack [4, 6, 2]; visited set(4)
        cur 1; stack [4, 6, 2, 3, 1]; visited set(4,2); res [1]
        cur 3; stack [4, 6, 2, 3]; visited set(4,2); res[1]
        cur 2; stack [4, 6, 2]; visited set(4,2); res[1,3]
        cur 6; stack [4, 6]; visited set(4,2); res[1,3,2]
        cur 5; stack [4, 6, 7, 5]; visited set(4,2,6); res[1,3,2,5]
        cur 7; stack [4, 6, 7]; visited set(4,2,6); res[1,3,2,5,7]
        cur 6; stack [4, 6]; visited set(4,2,6); res[1,3,2,5,7,6]
        cur 4; stack [4]; visited set(4,2,6); res[1,3,2,5,7,6,4]
        stack []; visited set(4,2,6); res[1,3,2,5,7,6,4]

            1
             \
              2
             /
            3 

        cur 1; stack [1];
        cur 2; stack [1, 2]; visited set(1)
        cur 3; stack [1, 2, 3]; visited set(1, 2); res [3]
        cur 2; stack [1, 2]; visited set(1,2); res [3, 2]
        cur 1; stack [1]; visited set(1,2); res [3, 2, 1]

            1
           / \
          4   2
         /
        3

        # End of walkthrough ====================================

        res = []
        if root:
            stack = [root]
            pre = None # pre node for identifying visited parent node
            while stack:
                cur = stack[-1]
                while (pre is None or (pre is not cur.left and pre is not cur.right)) and (cur.right is not None or cur.left is not None):
                    if cur.right:
                        stack.append(cur.right)
                    if cur.left:
                        stack.append(cur.left)
                        cur = cur.left
                    else:
                        cur = cur.right

                res.append(cur.val)
                pre = cur
                stack.pop()
        return res
        
        # use a stack with a set
        # res = []
        # if root:
        #     visited = set()
        #     stack = [root]
        #     while stack:
        #         cur = stack[-1]
        #         while cur not in visited and (cur.right is not None or cur.left is not None):
        #             visited.add(cur)
        #             if cur.right:
        #                 stack.append(cur.right)
        #             if cur.left:
        #                 stack.append(cur.left)
        #                 cur = cur.left
        #             else:
        #                 cur = cur.right

        #         res.append(cur.val)
        #         stack.pop()
        # return res