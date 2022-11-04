# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
297_serialize-and-deserialize-binary-tree LeetCode

Solution: 
    - BFS (leetcode native): use deque and record if next_level has ensuing children
    - DFS (recursive): 
        - serialize: use List as global variable instead of str (immutable)
        - deserialize: use iter() of List instead of using pop()
'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

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

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        #if not root:
        #    return 'null'
        #res = ''
        #q = deque([(root,1)])
        #next_level = False
        #level = 1
        #while q:
        #    cur, cur_level = q.popleft()
        #    if cur_level > level:
        #        if next_level:
        #            level = cur_level
        #            next_level = False
        #        else:
        #            break    
        #    if cur:    
        #        res += str(cur.val) + ','
        #        q.append((cur.left, cur_level+1))
        #        q.append((cur.right, cur_level+1))
        #        if cur.left or cur.right:
        #            next_level = True
        #    else:    
        #        res += 'null,' 
        #return res.strip(',')       
        
        def helper(cur):
            if cur:
                res.append(str(cur.val))
                helper(cur.left)
                helper(cur.right)
            else:
                res.append('null')
        
        res = []
        helper(root)
        return ' '.join(res)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        #vals = data.split(',')
        #if vals[0] == 'null':
        #    return None
        #root = TreeNode(vals[0])
        #q = deque([root])
        #for i in range(1, len(vals), 2):
        #    cur = q.popleft()
        #    if vals[i] != 'null':
        #        cur.left = TreeNode(vals[i])
        #        q.append(cur.left)
        #    else:
        #        cur.left = None
        #    if vals[i+1] != 'null':
        #        cur.right = TreeNode(vals[i+1])
        #        q.append(cur.right)
        #    else:
        #        cur.right = None
        #        
        #return root
        
        #def helper(vals):
        #    if vals[0] == 'null':
        #        vals.pop(0)
        #        return None
        #    cur = TreeNode(int(vals[0]))
        #    vals.pop(0)
        #    cur.left = helper(vals)
        #    cur.right = helper(vals)
        #    return cur
#
        #vals = data.split()    
        #root = helper(vals)
        #return root
    
        def helper(vals):
            val = next(vals)
            if val == 'null':
                return None
            cur = TreeNode(int(val))
            cur.left = helper(vals)
            cur.right = helper(vals)
            return cur

        vals = iter(data.split())   
        return helper(vals)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))