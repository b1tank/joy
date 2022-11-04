// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
679_24-game LeetCode

Solution: 
    - backtracking
    - non-commutative: - and / 
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
    double eps = 1e-6;
    bool judge_helper(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < eps;
        }
        if (nums.size() == 0) return false;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    vector<double> nums_copy;
                    for (int k = 0; k < nums.size(); k++) {
                        if (k != i && k != j) {
                            nums_copy.push_back(nums[k]);
                        }
                    }
                    
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && j > i) continue; // skip duplicate for + and * (commutal)
                        if (k == 0) nums_copy.push_back(nums[i] + nums[j]);
                        if (k == 1) nums_copy.push_back(nums[i] * nums[j]);
                        if (k == 2) nums_copy.push_back(nums[i] - nums[j]);
                        if (k == 3) {
                            if (nums[j] > eps) {
                                nums_copy.push_back(nums[i] / nums[j]);
                            } else {
                                continue;
                            }
                        }
                        if (judge_helper(nums_copy)) return true;
                        nums_copy.pop_back();
                    }
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> nums_d(nums.begin(), nums.end());
        return judge_helper(nums_d);
    }
};