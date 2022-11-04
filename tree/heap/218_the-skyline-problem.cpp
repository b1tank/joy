// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
218_the-skyline-problem LeetCode

Solution: 
    - multiset instead of heap 
        - O(LogN) for removing key (and insert)
    - multiset instead of set
        - maintain equivalent elements (ms.equal_range(key).first)
    - multiset instead of unordered_set
        - ordered (*ms.rbegin() is the max value)
    - sort container 
        - sort(v.begin(), v.end(), compare)
        - compare is a static function or function object (http://www.cplusplus.com/reference/algorithm/sort/)
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class Solution {

    typedef pair<int, int> pi;

    static bool compare(pi& pi1, pi& pi2) { // static required
        if (pi1.first != pi2.first) return pi1.first < pi2.first;
        return pi1.second > pi2.second; // 3 edge cases: up/up, down/up, down/down (ref: https://zxi.mytechroad.com/blog/tree/leetcode-218-the-skyline-problem/)
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pi> seq;
		for (const vector<int> & building : buildings) {
			seq.emplace_back(building[0], building[2]);
			seq.emplace_back(building[1], -building[2]);
		}
        
        sort(seq.begin(), seq.end(), compare); // http://www.cplusplus.com/reference/algorithm/sort/
        
        multiset<int> ms{0}; // adding a init height 0 for simplicity (http://www.cplusplus.com/reference/set/multiset/)
        vector<vector<int>> ret;
        for (const auto& s : seq) {
            if (s.second > 0) {
                if (s.second > *ms.rbegin()) {
                    ret.push_back(vector<int>{s.first, s.second});
                }
                ms.insert(s.second);
            } else {
                // handling two cases actually below: either cur_height is > 2nd-highest (point added) or <= 2nd-highest (no point added)
                ms.erase(ms.equal_range(-s.second).first); // erase only one height with the same value (edge case: e.g. i[[0,2,3],[2,5,3]])
                if (-s.second > *ms.rbegin()) {
                    ret.push_back(vector<int>{s.first, *ms.rbegin()});
                }
            }
        }
        return ret;
    }
};