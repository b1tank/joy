// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
53_maximum-subarray LeetCode

Solution: 
    - One-pass greedy
        - O(N)
    - One-pass in-place DP
        - O(N)
    - Divide-and-conquer
        - O(NlogN)
    - Ref: https://leetcode.com/articles/sliding-window-maximum/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {    

        // One-pass in-place DP
        // int n = nums.size(); 
        // int ret = nums[0];
        // for(int i = 1; i < n; ++i) {
        //     if (nums[i - 1] > 0) nums[i] += nums[i - 1];
        //     ret = max(nums[i], ret);
        // }
        // return ret;

        // One-pass greedy
        if (empty(nums)) return 0;
        int cur_sum = nums[0];
        int ret = cur_sum;
        int i = 1;
        int s = nums.size();
        for (int i = 1; i < s; i++) {
            // if (cur_sum < 0) {
            //     cur_sum = nums[i];
            // } else {
            //     if (cur_sum + nums[i] > 0) {
            //         cur_sum += nums[i];
            //     } else {
            //         cur_sum = nums[i];
            //     }
            // }
            cur_sum = max(cur_sum+nums[i], nums[i]);
            ret = max(ret, cur_sum);
        }
        return ret;
    }
};