# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
79_word-search LeetCode

Solution: 
    - DFS + backtracking using '#' in-place marking instead of set()
'''

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        def helper(board, i, j, w):           
            if not w:
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != w[0]:
                return False
            origin = board[i][j]
            board[i][j] = '#'
            res = helper(board, i-1, j, w[1:]) \
               or helper(board, i+1, j, w[1:]) \
               or helper(board, i, j-1, w[1:]) \
               or helper(board, i, j+1, w[1:]) 
            board[i][j] = origin
            return res         
            
        for i in range(len(board)):
            for j in range(len(board[0])):
                if helper(board, i, j, word):
                    return True
        return False         