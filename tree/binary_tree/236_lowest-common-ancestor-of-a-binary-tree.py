# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
236_lowest-common-ancestor-of-a-binary-tree on LeetCode

Solution: 
    - using stack-of-tuples inorder traversal and float-up-ancestor algorithm
    - recursive
    - parent pointers backtracking: use set or end-jump-back-to-the-other traversal
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def dfs(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None
        if root is p or root is q:
            return root
        left = self.dfs(root.left, p, q)
        right = self.dfs(root.right, p, q)
        if left and right:
            return root
        return left or right
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Beginning of walkthrough ==============================
            1
           / \
          2   3   
         / \   \
        8   4   7
           / \
          5   6

        # End of walkthrough ====================================

        # if p.val == root.val or q.val == root.val:
        #     return root
        # st = [(root, False, 0)]
        # flag_rank = -1
        # p_first = 1
        # cur = root
        # cur_rank = 0
        # res = None
        # while st:
        #     cur, visited, cur_rank = st.pop()
        #     while cur.left and not visited:
        #         st.append([cur, True, cur_rank])
        #         cur = cur.left
        #         cur_rank += 1
        #     if cur.right:
        #         st.append([cur.right, False, cur_rank+1])
        #         
        #     # visit cur
        #     if flag_rank == -1:    
        #         if cur.val == p.val or cur.val == q.val:
        #             flag_rank = cur_rank    
        #             res = cur
        #             if cur.val == q.val:
        #                 p_first = 0
        #     else:
        #         if cur_rank < flag_rank:
        #             flag_rank = cur_rank
        #             res = cur           
        #         if p_first and cur.val == q.val or (not p_first and cur.val == p.val):   
        #             return res

        # if not root:
        #     return None
        # if p.val == root.val or q.val == root.val:
        #     return root
        # 
        # left = self.lowestCommonAncestor(root.left, p, q)
        # right = self.lowestCommonAncestor(root.right, p, q)
        # if left and right:
        #     return root
        # return left or right 

        # return dfs(root, p, q)

        hm = {root: None}
        st = [root]
        while st:
            cur = st.pop()
            if cur.left:
                st.append(cur.left)
                hm[cur.left] = cur
            if cur.right:
                st.append(cur.right)
                hm[cur.right] = cur

        # # use set
        # s = set()
        # while p:
        #     s.add(p)
        #     p = hm[p]
        # while q:
        #     if q in s:
        #         return q
        #     q = hm[q]

        # use end-jump-back-to-the-other approach
        pointer1 = p
        pointer2 = q
        while pointer1 is not pointer2:
            if pointer1 is root:
                pointer1 = q
            else:
                pointer1 = hm[pointer1] 
            if pointer2 is root:
                pointer2 = p
            else:
                pointer2 = hm[pointer2] 
        return pointer1