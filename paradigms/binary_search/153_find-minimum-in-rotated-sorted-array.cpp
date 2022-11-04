// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
153_find-minimum-in-rotated-sorted-array LeetCode

Solution: 
    - l + (r - l) / 2 ---- to avoid int overflow !!!
    - be careful with different left and right boundary change patterns
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 3 4 5 1 2
        int s = nums.size();
        int l = 0;
        int r = s - 1;
        while (l < r) {
            int mid = l + (r - l) / 2; // avoid int overflow (don't use (r + l) / 2)!!!
            if (nums[mid] < nums[r]) {
                r = mid; // using r = mid - 1 will not work !!!
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
