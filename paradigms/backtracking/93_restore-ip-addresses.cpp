// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
93_restore-ip-addresses LeetCode

Solution: 
    - backtracking
    - s.substr(pos, length) or s.substr(pos)
*/

#include <iostream>
#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()
#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0)
#include <cstdlib> // rand() % 100 + 1
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set> // unordered_set, unordered_multiset
#include <set> // set, multiset
#include <unordered_map> // unordered_map, unordered_multimap
#include <map> // map, multimap
#include <utility> // pair<>
#include <tuple> // tuple<>
#include <algorithm> // reverse, sort, transform, find, remove, count, count_if
#include <memory> // shared_ptr<>, make_shared<>
#include <stdexcept> // invalid_argument

using namespace std;

class Solution {
    void dfs(int start, string s, vector<string>& res, vector<string>& ip) {
        if (start == s.size()) {
            if (ip.size() == 4) {
                ostringstream oss;
                for (auto& s : ip) {
                    oss << s << '.';
                }
                string ip_str = oss.str();
                ip_str.pop_back();
                res.push_back(ip_str);
            }
            return;
        }
        
        if (start > s.size() || ip.size() == 4) return; // check upper bound for start !!!
        
        if (s[start] == '0') {
            ip.push_back(s.substr(start, 1)); // substr 2nd argument is length !!!!!
            dfs(start+1, s, res, ip);
            ip.pop_back();
        } else {
            for (int i = 1; i < 4; i++) {
                string tmp = s.substr(start, i);
                if (stoi(tmp) <= 255) {
                    ip.push_back(tmp);
                    dfs(start+i, s, res, ip);
                    ip.pop_back();
                }
            }
        }
        
        // 1 {1}
        // 2 {1 0}
        // 4 {1 0 10}
        // 6 {1 0 10 24}
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // 101024
        // 1.0.10.24
        // 1.0.102.4
        // 10.10.2.4
        // 101.0.2.4
        
        vector<string> res;
        vector<string> ip;
        dfs(0, s, res, ip);
        return res;
    }
};