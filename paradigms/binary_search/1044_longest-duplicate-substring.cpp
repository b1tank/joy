// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1044_longest-duplicate-substring LeetCode

Solution: 
    - binary search to find the length
    - Rabin-Karp rolling hash algorithm (take modulus to avoid overflow)
        - long long: power_base, hash, mod
        - base of 26 (converting char to int) 
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
    pair<int, int> found(vector<int> si, int len) {
        // bcdefabcd
        // len = 3
        // 123
        int n = si.size();
        int base = 26;
        long long hash = 0;
        long long power_base = 1;
        long long mod = 1l << 32; // has to be long long as well !!!
        for (int i = 0; i < len; i++) {
            hash = (hash * base + si[i]) % mod;
            power_base = (power_base * base) % mod;
        }
        unordered_set<long long> s{hash};
        for (int j = len; j < n; j++) {
            hash = ((hash * base + si[j]) % mod - power_base * si[j-len]) % mod; // take mod of (hash * base + si[j]) like above !!!!
            //  hash = (hash * base + si[j] - power_base * si[j-len]) % mod; // return wrong result - "aabaadca" instead of "aeeebaabd"
            if (s.find(hash) != s.end()) {
                pair<int, int> p(j-len+1, len); // don't miss +1
                return p; // return make_pair<int, int>(j-len+1, len) ===>>> compiler error: no known conversion from 'int' to 'int &&' for 2nd argument !!!
            } else {
                s.insert(hash);
            }
        }
        return make_pair<int, int>(0, -1);
    }
public:
    string longestDupSubstring(string S) {
        // bacaca
        // 1 5 0 0
        // 102020
        
        int n = S.size();
        int l = 1; 
        int r = n-1;
        vector<int> si;
        for (auto& c : S) {
            si.push_back(c - 'a');
        }
        int res_start = 0;
        int res_len = 0;
        while (l <= r) { // don't forget to check when l == r
            int mid = l + (r - l) / 2;
            pair<int, int> p = found(si, mid);
            if (p.second == mid) {
                res_start = p.first;
                res_len = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return S.substr(res_start, res_len);
    }
};