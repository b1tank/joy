// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
409_longest-palindrome LeetCode

Solution: 
    - hashset
        - OR a 26*2 int array
        - OR a 26*2 bitset
    - odd and even (cancel each other out for a pair)
*/

#include <iostream>
#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()
#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0)
#include <cstdlib> // rand() % 100 + 1
#include <vector>
#include <forward_list> // singly-linked list
#include <list> // doubly-linked list
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set> // unordered_set, unordered_multiset
#include <set> // set, multiset
#include <bitset> // bitset
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
    int longestPalindrome(string s) {
        //  a 1
        //  A 3 2
        //  v 5 4

        // int res = 0;
        // unordered_set<char> set;
        // for (auto c : s) {
        //     if (set.find(c) != set.end()) {
        //         res += 2; 
        //         set.erase(c);
        //     } else {
        //         set.insert(c);
        //     }
        // }
        
        // return set.empty() ? res : res + 1;

        int res = 0;
        bitset<26*2> bset(0);
        for (auto c : s) {
            int index = c - 'a';
            if (index < 0 || index > 25) {
                index = 26 + c - 'A';
            }

            if (bset[index] == 1) {
                res += 2; 
            }
            bset.flip(index);
        }
        
        return !bset.any() ? res : res + 1;
    }
};