// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
340_longest-substring-with-at-most-k-distinct-characters LeetCode

Solution: 
    - sliding window with a hashmap
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // abace 2
        if (k == 0) return k;
        int n = s.size();
        unordered_map<char, int> hm;
        int left = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (hm.find(s[i]) == hm.end()) {
                while (hm.size() == k) {
                    hm[s[left]]--;
                    if (hm[s[left]] == 0) {
                        hm.erase(s[left]);
                    }
                    left++;
                }
                hm.insert({s[i], 1});
            } else {
                hm[s[i]]++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};