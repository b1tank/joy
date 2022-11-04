# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
151_reverse-words-in-a-string LeetCode

Solution: 
    - O(n) space (for O(1) space version, see 186_reverse-words-in-a-string-ii)
'''

class Solution:
    def reverseWords(self, s: str) -> str:
        res = []
        e = 0
        whitespace = True
        for i in range(len(s)-1, -1, -1):   
            if whitespace: 
                if s[i] != ' ':
                    e = i
                    whitespace = False
            else:
                if s[i] == ' ':
                    res.append(s[i+1:e+1])
                    whitespace = True
        if not whitespace:            
            res.append(s[:e+1])
        return ' '.join(res)