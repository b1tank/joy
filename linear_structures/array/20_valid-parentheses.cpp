// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
20_valid-parentheses LeetCode

Solution: 
    - stack
*/

#include <stack>
#include <string>

class Solution {
private:
    bool is_left(const char & c) {
        return c == '{' || c == '(' || c == '[';
    };
    char left_of(const char & c) {
        switch (c) {
            case ')':   
                return '(';
            case '}':   
                return '{';
            case ']':   
                return '[';
            default: 
                return ' ';
        }       
    };
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (char& c : s) {
            if (is_left(c)) {
                st.push(c);
            } else {
                if (st.empty() || st.top() != left_of(c)) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};