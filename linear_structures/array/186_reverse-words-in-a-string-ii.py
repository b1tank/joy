# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
186_reverse-words-in-a-string-ii LeetCode

Solution: 
    - O(1) space
    - for this particular problem, the "remove whitespaces" code is unnecessary
'''

class Solution:
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        
        if not s:
            return     
        # remove leading, trailing and redundant whitespaces
        i, j = 0, 0
        while j < len(s):
            while j < len(s) and s[j] == ' ':
                j += 1
            while j < len(s) and s[j] != ' ':
                s[i] = s[j]
                i += 1
                j += 1
            while j < len(s) and s[j] == ' ':
                j += 1
            if j < len(s):
                s[i] = ' '
                i += 1    
                
        del s[i:] # do NOT use s[:i], which is shallow copy and will not modify s in place        
                
        # reverse the whole list
        i, j = 0, len(s)-1
        while i<j:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1

        # reverse each word
        def reverseWord(s, start, end):
            i, j = start, end
            while i<j:
                s[i], s[j] = s[j], s[i]
                i += 1
                j -= 1

        l, k = 0, 0        
        while k < len(s):
            while k < len(s) and s[k] != ' ':
                k += 1
            reverseWord(s, l, k-1)    
            k += 1
            l = k
        return    