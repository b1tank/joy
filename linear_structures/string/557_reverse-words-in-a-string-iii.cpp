// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
557_reverse-words-in-a-string-iii LeetCode

Solution: 
    - std::reverse() STL function
    - sstream
        - getline(iss, token, delimiter)
        - oss.str()
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
    string reverseWords(string s) {
        istringstream iss(s);
        ostringstream oss;
        string token;
        while (getline(iss, token, ' ')) {
            reverse(token.begin(), token.end());
            oss << token << ' ';
        }
        string res{oss.str()};
        if (!res.empty()) res.pop_back();
        return res;
    }
};