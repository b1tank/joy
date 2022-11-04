// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1239_maximum-length-of-a-concatenated-string-with-unique-characters LeetCode

Solution: 
    - bitset
        - fast for set union
        - size must be defined: bitset<26>
        - index 0 from the right end instead of left end !!!!
        - .set(), .reset(), .flip()
        - .any(), .none(), .all()
        - .count(), .size()
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
    // set<char> union_set(set<char> s1, set<char> s2) {
    //     set<char> ret;
    //     for (char c : s1) {
    //         ret.insert(c);
    //     }
    //     for (char c : s2) {
    //         ret.insert(c);
    //     }
    //     return ret;
    // }
    // set<char> make_set(string& s) {
    //     set<char> ret;
    //     for (char c : s) {
    //         ret.insert(c);
    //     }
    //     return ret;
    // }
public:
    int maxLength(vector<string>& arr) {
        // 138254
        // 123234
        vector<bitset<26>> dp;
        int ret = 0;
        for (int i = 0; i < arr.size(); i++) {
            bitset<26> set_i(0);
            for (char c : arr[i]) {
                set_i.set(c - 'a');
            }
            int n = arr[i].size();
            if (set_i.count() == n) {
                for (int i = dp.size()-1; i >= 0; i--) {
                    if ((dp[i] & set_i).none()) {
                        ret = max(ret, (int)dp[i].count()+n); // must cast from unsigned int to int; otherwise, max() not found
                        dp.push_back(dp[i] | set_i);
                    }
                }
                ret = max(ret, n);
                dp.push_back(set_i);
            }
        }
        return ret;
        // vector<set<char>> dp;
        // int ret = 0;
        // for (int i = 0; i < arr.size(); i++) {
        //     set<char> set_i = make_set(arr[i]);
        //     if (set_i.size() == arr[i].length()) {
        //         for (int i = dp.size()-1; i >= 0; i--) {
        //             set<char> com = union_set(dp[i], set_i);
        //             if (dp[i].size() + set_i.size() == com.size()) {
        //                 ret = ret >= com.size() ? ret : com.size();
        //                 dp.push_back(com);
        //             }
        //         }
        //         ret = ret >= set_i.size() ? ret : set_i.size();
        //         dp.push_back(set_i);
        //     }
        // }
        // return ret;
    }
};