// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
44_wildcard-matching LeetCode

Solution: 
    - recursion with memoization using hashmap
        - Time: O(2^min(M, N/2)) (Time limit exceeded)
        - Space: O(2^min(M, N/2))
    - DP
        - Time: O(MN)
        - Space: O(MN)
    - backtracking
        - Time: O(Mlog(N)), O(min(M,N)) for the best case
        - Space: O(1)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// struct pair_hash {
//     template <class T1, class T2>
//     std::size_t operator () (const std::pair<T1,T2> &p) const {
//         auto h1 = std::hash<T1>{}(p.first);
//         auto h2 = std::hash<T2>{}(p.second);
// 
//         // Mainly for demonstration purposes, i.e. works but is overly simple
//         // In the real world, use sth. like boost.hash_combine
//         return h1 ^ h2;  
//     }
// };
class Solution {
    // bool helper(string s, string p, unordered_map<pair<string, string>, bool, pair_hash> hm) {
    //     if (hm.find(make_pair(s,p)) != hm.end()) {
    //         return hm[make_pair(s,p)];
    //     }
    //     if (p == s || p == '*') {
    //         hm[make_pair(s,p)] = true;
    //     } else if (p.empty() || s.empty()) {
    //         hm[make_pair(s,p)] = false;
    //     } else if (p[0] == '?' || p[0] == s[0]) {
    //         hm[make_pair(s,p)] = helper(s.substr(1, s.size()-1), p.substr(1, p.size()-1), hm);
    //     } else if (p[0] == '*') {
    //         hm[make_pair(s,p)] = helper(s, p.substr(1, p.size()-1), hm) || helper(s.substr(1, s.size()-1), p, hm);
    //     }
    //     return hm[make_pair(s,p)];
    // }
    // void removeDuplicateStars (string& p) {
    //     stringstream ss;
    //     string prev = '';
    //     for (auto c : p) {
    //         if (c != '*' || prev != '*') {
    //             ss << c;
    //         }
    //         prev = c;
    //     }
    //     ss >> p;
    // }
public:
    bool isMatch(string s, string p) {
        
        // backtracking
        // 
        // only last '*' in the DFS traversal needs to be backtracked because previous '*'s does not need match more sequence of characters, which can be anyway matched by the last '*' !!!
        // e.g. abcXXXXbcaXXXXabc
        //      ab*XXXX*bc
        // when the traversal reaches the 2nd '*' for the first time, the 1st (left) sequence of 'XXXX' must have been matched by the pattern 'XXXX' between two '*'s; if backtracked to the 1st '*', to reach the 2nd '*' for the second time, the 1st '*' would match until before the 2nd (right) sequence of 'XXXX', i.e. 'cXXXXbca'; but it has the same effect if the 2nd '*' includes the sequence of 'bcaXXXX', which must have been inspected when the 2nd '*' was traversed for the first time
        
        int m = s.size();
        int n = p.size();
        int i = 0;
        int j = 0;
        int s_mark = -1; 
        int p_mark = -1;
        while (i < m) {
            if (j < n && (p[j] == s[i] || p[j] == '?')) {
                ++i;
                ++j;
            } else if (j < n && p[j] == '*') {
                s_mark = i;
                ++j;
                p_mark = j;
            } else if (p_mark == -1) { // no '*' has been found
                return false;
            } else {
                i = s_mark;
                ++s_mark;
                j = p_mark;
            }
        }
        while (j < n) {
            if (p[j] != '*') return false;
            ++j;
        }
        return true;
        
        // DP
        // 
        // int m = s.size();
        // int n = p.size();
        // vector<vector<bool>> dp( m+1, vector<bool>(n+1, false) ); // empty string at index 0 !!!
        // dp[0][0] = true;
        // // for (auto i = 1; i < m+1; ++m) {
        // //     dp[i][0] = false;
        // // }
        // for (auto j = 1; j < n+1; ++j) { // n as the last index !!!
        //     dp[0][j] = dp[0][j-1] && p[j-1] == '*';
        // }
        // 
        // for (auto i = 1; i < m+1; ++i) { 
        //     for (auto j = 1; j < n+1; ++j) {
        //         if (dp[i-1][j-1]) {
        //             dp[i][j] = p[j-1] == s[i-1] || p[j-1] == '?' || p[j-1] == '*'; // p[j-1] is the right position in the string instead of p[j] !!!
        //         } else {
        //             dp[i][j] = (dp[i-1][j] || dp[i][j-1]) && p[j-1] == '*';
        //         }
        //     }
        // }
        // return dp[m][n];
        
        // recursion with hashmap
        // 
        // unordered_map<pair<string, string>, bool, pair_hash> hm;
        // removeDuplicateStars(p);
        // return helper(s, p, hm);
    }
};