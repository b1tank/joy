// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1156_swap-for-longest-repeated-character-substring LeetCode

Solution: 
    - 3 scenarios:
        - aaabcea: swap to extend by just 1
        - aaabaaefa: swap to extend by second substring + 1
            - aaabaa: => aaaaab, extend by just second substring
    - just need to know count of certain character
        - use hashmap
    - need to know all substrings with repeated characters and their length
        - use vector
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
    int maxRepOpt1(string text) {
        vector<int> freq(26);
        vector<pair<int, int>> leng;
        
        int n = text.size();
        int left = 0;
        for (int i = 0; i < n; i++) {
            freq[text[i] - 'a']++;
            if (text[i] != text[left]) {
                leng.emplace_back(text[left], i-left);
                left = i;
            }
        }
        leng.emplace_back(text[left], n-left); // last substring needs to be added !!!
        
        int m = leng.size();
        int res = n > 0 ? 1 : 0;
        for (int j = 0; j < m; j++) {
            int cur_len = leng[j].second;
            if (j < m - 2 && leng[j].first == leng[j+2].first && leng[j+1].second == 1) {
                cur_len += leng[j+2].second;
            }
            res = max(res, cur_len + (cur_len < freq[leng[j].first - 'a'] ? 1 : 0));
        }
        
        return res;
    }
};