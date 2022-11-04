# Author: b1tank
# Email: b1tank@outlook.com
#=================================

'''
8_string-to-integer-atoi LeetCode

Solution: 
    - decompose tasks sequentially
    - check corner cases after building skeleton
'''

class Solution:
    def myAtoi(self, s: str) -> int:
        
        # def char2digit(c):
        #     return ord(c) - ord('0')
        # 
        # if not s:
        #     return 0
        # i = 0
        # w = {' ', '-', '+'}
        # found = ord(s[i]) >= ord('0') and ord(s[i]) <= ord('9')
        # res = 0
        # negative = False
        # while (s[i] in w and not found) or (ord(s[i]) >= ord('0') and ord(s[i]) <= ord('9')):
        #     if not found:
        #         if s[i] == '-':
        #             negative = True
        #             found = True
        #         elif s[i] == '+':
        #             found = True
        #         elif ord(s[i]) >= ord('0') and ord(s[i]) <= ord('9'):
        #             found = True
        #             res = res * 10 + char2digit(s[i])   
        #     else:
        #         if ord(s[i]) >= ord('0') and ord(s[i]) <= ord('9'):
        #             res = res * 10 + char2digit(s[i])   
        #         else:
        #             return 0    
        #     i += 1
        #     if i >= len(s):
        #         break
        # if negative:
        #     res = 0 - res            
        #     return max(-2147483648, res)        
        # return min(2147483647, res)
    
        # empty string
        if not s:
            return 0
        
        # ignore all prefix whitespaces
        i = 0
        while i < len(s) and s[i] == ' ':
            i += 1
            
        # get sign if any    
        sign = 1
        if i < len(s):
            if s[i] == '-':
                sign = -1
                i += 1
            elif s[i] == '+':
                i += 1
        
        # add digit to result
        res = 0
        max_int = 2147483647
        min_int = -2147483648
        while i < len(s) and s[i].isdigit():
            if (res > max_int // 10 or (res == max_int // 10 and ord(s[i]) - ord('0') > max_int % 10)):
                if sign == 1:
                    return max_int
                else:
                    return min_int
            res = res * 10 + ord(s[i]) - ord('0')
            i += 1
        return res * sign    