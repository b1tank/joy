// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
13_roman-to-integer LeetCode

Solution: 
    - unordered_map
        - initialization 
            - hm({ {first, second}, {first2, second2}, ... });
        - check if key exists
            - if (hm.find(key) != hm.end()) {}
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // int i = 0;
        // int ret = 0;
        // int n = s.length();
        // unordered_map<char, int> hm({
        //     {'I', 1},
        //     {'V', 5},
        //     {'X', 10},
        //     {'L', 50},
        //     {'C', 100},
        //     {'D', 500},
        //     {'M', 1000}
        // });
        // unordered_set<char> sp({'I', 'X', 'C'});
        // while (i < n) {
        //     if (sp.find(s[i]) != sp.end() && i+1 < n && (hm[s[i+1]] / hm[s[i]] == 5 || hm[s[i+1]] / hm[s[i]] == 10)) {
        //             ret += hm[s[i+1]] - hm[s[i]];
        //             i += 2;
        //     } else {
        //         ret += hm[s[i]];
        //         i++;
        //     }
        // }
        // return ret;

        unordered_map<char, int> um{
            {  'I',            1},
            {  'V',            5},
            {  'X',            10},
            {  'L',            50},
            {  'C',            100},
            {  'D',            500},
            {  'M',            1000}
        };
        int prev = 0;
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            int cur = um[s[i]];
            if (prev != 0 && (cur / prev == 5 || cur / prev == 10)) {
                ret -= prev * 2;        
            }
            prev = cur;
            ret += cur;
        }
        return ret;
    }
};