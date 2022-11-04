// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
136_single-number LeetCode

Solution: 
    - any number xor with 0 => number itself
    - any number xor with itself => 0
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 1 ^ 1 ^ 1 = 1
        // 0 ^ 1 ^ 1 = 0
        // 1 ^ 0 ^ 0 = 1
        // 0 ^ 0 ^ 0 = 0
        // exclusive or
        
        int ret = nums[0];
        for (int i = 1 ; i < nums.size(); i++) {
            ret ^= nums[i];
        }
        return ret;
        
        // set and math
        // unordered_set<int> us(nums.begin(), nums.end());
        // return accumulate(us.begin(), us.end(), 0) * 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};