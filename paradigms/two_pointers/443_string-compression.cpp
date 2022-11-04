// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
443_string-compression LeetCode

Solution: 
    - two pointers 
        - slow and fast
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
public:
    int compress(vector<char>& chars) {
        // a a a b c c c
        int n = chars.size();
        if (n < 2) {
            return n;
        }
        int l = 0;
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n && chars[i] == chars[l]) {
                count++;  
            } else {
                if (count > 1) {
                    string tmp = to_string(count);
                    for (auto& c : tmp) {
                        chars[++l] = c;
                    }
                }
                l++;
                if (i < n) chars[l] = chars[i];
                count = 1;
            }
        }
        chars.erase(chars.begin() + l, chars.end());
        return chars.size();
    }
};