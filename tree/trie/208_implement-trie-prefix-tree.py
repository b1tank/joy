# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
208_implement-trie-prefix-tree on LeetCode

Solution: 
    - Trie: do not need a val in TrieNode; use isEnd boolean flag
'''

class TrieNode:
    #def __init__(self, val):
    def __init__(self):
        #self.val = val
        self.isEnd = False
        self.next = {}
        
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        #self.root = TrieNode('')
        self.root = TrieNode()
        self.root.isEnd = True

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur = self.root
        for w in word:
            if w not in cur.next:
                #cur.next[w] = TrieNode(w)
                cur.next[w] = TrieNode()
            cur = cur.next[w]
        cur.isEnd = True        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self.root
        for w in word:
            if w in cur.next:
                cur = cur.next[w]
            else:
                return False
        return cur.isEnd    

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur = self.root
        for w in prefix:
            if w not in cur.next:
                return False
            cur = cur.next[w]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)