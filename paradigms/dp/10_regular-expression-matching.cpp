// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
10_regular-expression-matching LeetCode

Solution: 
    - recursive: time limited
    - dp: 
        - top-down (recursive -> memoization)
        - bottom-up (normal dp)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int isMatchWithMemo(int i, int j, const string & s, const string & p, vector<vector<int>> & memo) {
        // "a"
        // "ab*"
        //
        // "bbb"
        // ".*a"
        if (memo[i][j] != 2) return memo[i][j];
        bool first_match = i < s.length() && (s[i] == p[j] || p[j] == '.');
        if (j+1 < p.length() && p[j+1] == '*') {
            memo[i][j] = isMatchWithMemo(i, j+2, s, p, memo) || (first_match && isMatchWithMemo(i+1, j, s, p, memo));
        } else {
            memo[i][j] = first_match && isMatchWithMemo(i+1, j+1, s, p, memo); // don't forget first_match !!!
        }
        // cout << i << ' ' << j << ' ' << memo[i][j] << endl;
        return memo[i][j];
    }
    bool isMatch(string s, string p) {

        // recursive
        // if (empty(p)) {
        //     return empty(s);
        // }
        // bool first_match = !empty(s) && (s[0] == p[0] || p[0] == '.');
        // if (p.length() > 1 && p[1] == '*') {
        //     return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        // } else {
        //     return first_match && isMatch(s.substr(1), p.substr(1));
        // }

        // dp (top-down, memoization)
        if (empty(p)) {
            return empty(s);
        }
        int m = s.length();
        int n = p.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1, 2)); // 2 as a sentinel value; 0, 1 mean false, true 
        memo[m][n] = 1;
        return isMatchWithMemo(0, 0, s, p, memo) == 1;

        // dp (bottom-up, normal dp)
        // "aa"
        // "a*"
        // dp:
        // [F F F]
        // [F F F]
        // [F F T]
        //
        // [T F F]
        // [T F F]
        // [T T T]
        // 
        // if (empty(p)) {
        //     return empty(s);
        // }
        // int m = s.length();
        // int n = p.length();
        // vector<vector<bool>> memo(m+1, vector<bool>(n+1)); // use bool instead of int
        // memo[m][n] = true;

        // for (int i = m; i >= 0; i--) {
        //     for (int j = n-1; j >= 0; j--) { 
        //         // when j == n, i < m, it would always be false; 
        //         // if start with j = n, memo[m][n] will be overwritten as false, so don't do it !!!
        //         bool first_match = i < m && (s[i] == p[j] || p[j] == '.');
        //         if (j + 1 < n && p[j+1] == '*') {
        //             memo[i][j] = memo[i][j+2] || (first_match && memo[i+1][j]);
        //         } else {
        //             memo[i][j] = first_match && memo[i+1][j+1];
        //         }
        //     }
        // }
        // return memo[0][0];
    }
};