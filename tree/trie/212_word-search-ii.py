# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
212_word-search-ii LeetCode

Solution: 
    - Trie + DFS + backtracking
    - similar to word search 
'''

class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.next = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def addWord(self, word):   
        cur = self.root
        for w in word:
            if w not in cur.next:
                cur.next[w] = TrieNode()   
            cur = cur.next[w]    
        cur.isEnd = True    
    
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # ['o','a','a','n'],
        # ['e','t','a','e'],
        # ['i','h','k','r'],
        # ['i','f','l','v']
        #
        # [["a","b"],["a","a"]]
        # ["aba","baa","bab","aaab","aaa","aaaa","aaba"]
        #   .     root
        #        /    \
        #   .   a.     b
        #   .  / \      \
        #   . a.  b      a
        #    / \   \    / \
        #   a*  b   a* a*  b
        #. / \.  \
        # a.  b*  a*
        def findPathInTrie(board, i, j, trienode, track, res):           
            if trienode.isEnd:
                res.add(track)
                # trienode.isEnd = False # Optional: avoid adding duplicate; it's resolved by set() though
                # Do NOT return here, otherwise, longer valid word will be omitted (e.g. "aaab" will be omitted since "aaa" is valid)
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] not in trienode.next:
                return
            origin = board[i][j]
            board[i][j] = '#'
            
            track += origin # keep track of valid prefix
            
            findPathInTrie(board, i-1, j, trienode.next[origin], track, res)
            findPathInTrie(board, i+1, j, trienode.next[origin], track, res)
            findPathInTrie(board, i, j-1, trienode.next[origin], track, res)
            findPathInTrie(board, i, j+1, trienode.next[origin], track, res)
            
            # NO need to reset the value of "track" since it's immutable string, which is passed by reference but not modified within the recursive function calls !!!
            # Good reference: https://medium.com/@tyastropheus/tricky-python-ii-parameter-passing-for-mutable-immutable-objects-10e968cbda35            

            board[i][j] = origin
            
        # construct the trie
        wordTrie = Trie()
        for word in words:
            wordTrie.addWord(word)
    
        res = set() # global variable
        for i in range(len(board)):
            for j in range(len(board[0])):
                findPathInTrie(board, i, j, wordTrie.root, '', res) # an empty string for tracking prefix
        return list(res)         