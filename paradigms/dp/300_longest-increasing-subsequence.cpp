// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
300_longest-increasing-subsequence(LIS) LeetCode

Solution: 
    - DP
        - 1D array (length including the ending number)
        - O(N^2)
    - DP (with binary search)
        - Patience Sorting with 1D array (https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf)
        - pointer to prev can help print the entire LIS
        - O(NlogN)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // shortest cpp
        // vector<int> dp;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     auto it = std::lower_bound(dp.begin(), dp.end(), nums[i]);
        //     if (it == dp.end())
        //         dp.push_back(nums[i]);
        //     else
        //         *it = nums[i];
        // }
        // return dp.size();

        // dp: [1, 3, 5, 7]
        // nums[i] == 3
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp;
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int r = dp.size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums[i] > dp[mid])
                {
                    l = mid + 1;
                }
                else if (nums[i] < dp[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid;
                    break;
                }
            }
            if (l == dp.size())
            {
                dp.push_back(nums[i]);
            }
            else
            {
                dp[l] = nums[i];
            }
        }
        return dp.size();
    }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n == 0) return 0;
    //     vector<int> dp(n, 1);
    //     int ret = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[j] < nums[i]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //         }
    //         ret = max(ret, dp[i]);
    //     }
    //     return ret;
    // }
};