# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
211_add-and-search-word-data-structure-design LeetCode

Solution: 
    - Trie + recursive
'''

class TrieNode():
    def __init__(self, val):
        self.val = val
        self.next = {}
        self.isEnd = False
        
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode('')

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cur = self.root
        for w in word:
            if w not in cur.next:
                cur.next[w] = TrieNode(w)
            cur = cur.next[w]
        cur.isEnd = True
        

    def searchHelper(self, trienode, w):
        if not w:
            return trienode.isEnd # Do NOT forget isEnd check by directly return True !!!
        cur = trienode
        res = False
        if w[0] == '.':
            for n in cur.next:
                res = res or self.searchHelper(cur.next[n], w[1:])
        else:
            if w[0] in cur.next:
                res = res or self.searchHelper(cur.next[w[0]], w[1:])
        return res 
        
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.searchHelper(self.root, word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)