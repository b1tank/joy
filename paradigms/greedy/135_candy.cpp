// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
135_candy LeetCode

Solution: 
    - greedy: left-to-right, right-to-left
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
    int candy(vector<int>& ratings) {
        // 1 3 4 5 2
        
        // 1 2 3 4 1
        // 1 2 1
        
        int n = ratings.size();
        vector<int> candy(n,1);
        for (int i = 0; i < n-1; i++) {
            if (ratings[i+1] > ratings[i] && candy[i+1] <= candy[i]) candy[i+1] = candy[i] + 1;
        }
        for (int i = n-1; i > 0; i--) {
            if (ratings[i-1] > ratings[i] && candy[i-1] <= candy[i]) candy[i-1] = candy[i] + 1;
        }
        int res = 0;
        for (auto& c : candy) {
            res += c;
        }
        return n == 1 ? 1 : res;
    }
};