// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
171_excel-sheet-column-number LeetCode

Solution: 
    - left to right
    - right to left (Caution: power overflow on last iteration!)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int ret = 0;
        //for (int i = n-1; i >= 0; i--) {
        for (int i = 0; i < n; i++) {
            ret *= 26;
            ret += s[i] - 'A' + 1;
        }
        return ret;
    }
};