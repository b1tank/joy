# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
125_valid-palindrome LeetCode

Solution: 
    - out-of-bound checking !!!
    - C++: isalnum('a'), lower('A'); python: 'a'.isalnum(), 'A'.lower()
'''

class Solution:
    def isPalindrome(self, s: str) -> bool:
        #i, j = 0, len(s)-1
        #while i<j:
        #    if s[i].isalnum() and s[j].isalnum():
        #        if s[i].lower() != s[j].lower():
        #            return False
        #        else:
        #            i += 1
        #            j -= 1
        #    if not s[i].isalnum():
        #        i += 1
        #    if not s[j].isalnum():
        #        j -= 1
        #return True
    
        i, j = 0, len(s) - 1

        while i < j:
            while i < j and not s[i].isalnum(): # i < j checking to avoid out-of-bound error
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1

            if s[i].lower() != s[j].lower():
                return False

            i += 1
            j -= 1

        return True