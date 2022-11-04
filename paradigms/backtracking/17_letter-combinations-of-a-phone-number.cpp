// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
17_letter-combinations-of-a-phone-number LeetCode

Solution: 
    - DFS (backtracking)
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
    unordered_map<char, string> hm = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void dfs(string& s, int k, string cur, vector<string>& res) {
        int n = s.size();
        if (k == n-1) {
            for (auto c : hm[s[k]]) {
                res.push_back(cur + c);
            }
        } else {
            for (auto c : hm[s[k]]) {
                dfs(s, k+1, cur + c, res);
            }
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        dfs(digits, 0, "", res);
        return res;    
    }
};