// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
398_random-pick-index LeetCode

Solution: 
    - reservoir sampling (select k (k < n) in total n elements with each probability of being selected as k/n)
        - k == 1 for this case
    - reservoir sampling algorithm
        - reference: https://gregable.com/2007/10/reservoir-sampling.html
        - put first k elements in a reservoir (stream)
        - for each iteration i from k+1 to n: 
            - generate a random number r in [1, i]
                - if r <= k: ////// k/i
                    - generate a random number r in [1, k] ////// 1/k
                    - replace this r with i
                - for a number m staying in the reservoir: 1 - 1/k * k/i = (i-1)/i
        - m stays in the reservoir eventually: 1 * k/(k+1) * (k+1)/(k+2) * ... * (n-1)/n = k/n
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
    // unordered_map<int, vector<int>> hm;
    vector<int> ns;
public:
    Solution(vector<int>& nums) {
        ns = nums;
        
        // for (int i = 0; i < nums.size(); i++) {
        //     hm[nums[i]].push_back(i);
        // }
    }
    
    int pick(int target) {
        int res = -1;
        int count = 0;
        for (int i = 0; i < ns.size(); i++) {
            if (ns[i] != target) continue;
            if (rand() % (++count) == 0) res = i;
        }
        return res;
        
        // int r = rand() % hm[target].size();
        // return hm[target][r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */