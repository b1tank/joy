# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
720_Longest_Word_in_Dictionary on LeetCode

Solution: 
    - Trie: TrieNode has a value and a hashmap of child nodes
    - Depth First Search (DFS) implemented using both stack and recursive
'''


class TrieNode():

    def __init__(self, c):
        self.c = c
        self.next = {}  # key: c value of a child; value: a child TrieNode

class Trie(TrieNode):

    def __init__(self):
        self.c = ''
        self.next = {}

    def is_valid(self, word):
        cur = self
        for c in word:
            if c in cur.next:
                cur = cur.next[c]
            else:
                return False
        return '*' in cur.next

    def add_word(self, word):
        cur = self
        for c in word:
            if c not in cur.next:
                tn = TrieNode(c)
                cur.next[c] = tn
                cur = tn
            else:
                cur = cur.next[c]
        if '*' not in cur.next:
            cur.next['*'] = TrieNode('*')  # terminating node, which can be also implemented as a bool flag in TrieNode

class Solution():
    def lw_dfs(self, tn : TrieNode):
        '''DFS implementation for longest word searching.'''

        #********** stack DFS **********#
        stack = [n for n in tn.next.values()]
        max_sub_str = ''
        tmp = ''
        while stack:
            cur = stack.pop()
            if cur.c == '1':
                tmp = tmp[:-1]  # the last character is truncated from the tracked string when a marker TrieNode is hit
            else:
                if '*' in cur.next:
                    tmp = tmp + cur.c
                    stack.append(TrieNode('1'))  # a marker TrieNode to separate different levels
                    for n in cur.next.values():  # put all children on the stack
                        stack.append(n) 
                else:
                    if len(tmp) > len(max_sub_str) or (len(tmp) == len(max_sub_str) and tmp < max_sub_str):
                        max_sub_str = tmp  # update the longest word which is found
        return max_sub_str

        #********** recursive DFS **********#
        #if tn.c == '*' or ('*' not in tn.next and tn.c != ''):  # base case
        #    return ''
        #else:
        #    ret_str = tn.c
        #    max_sub_str = ''
        #    for nv in tn.next.values():  # use DFS to find longest words of all children
        #        tmp = self.lw_dfs(nv)
        #        if len(tmp) > len(max_sub_str) or (len(tmp) == len(max_sub_str) and tmp < max_sub_str):
        #            max_sub_str = tmp
        #    return ret_str + max_sub_str

    def longestWord(self, words):

        t = Trie()
        for w in words:
            t.add_word(w)

        return self.lw_dfs(t)

def main():

    s = Solution()

    words_1 = ["w","wo","wor","worl"]
    output_1 = s.longestWord(words_1)
    print(output_1)
    answer_1 = 'worl'
    print(output_1 == answer_1)

    words_2 = ["a", "banana", "app", "appl", "ap", "apply", "appla", "apple"]
    output_2 = s.longestWord(words_2)
    print(output_2)
    answer_2 = 'appla'
    print(output_2 == answer_2)

if __name__ == '__main__':
    main()
