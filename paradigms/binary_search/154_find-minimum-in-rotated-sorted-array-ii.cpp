// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
154_find-minimum-in-rotated-sorted-array-ii LeetCode

Solution: 
    - l + (r - l) / 2 ---- to avoid int overflow !!!
    - be careful with different left and right boundary change patterns
    - move less aggressively with the right pointer to tackle duplicates
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // int s = nums.size();
        // int l = 0;
        // int r = s - 1;
        // while (l < r) {
        //     int mid = l + (r - l) / 2;
        //     if (nums[mid] < nums[r] || nums[mid] < nums[l] || (nums[mid] == nums[r] && nums[mid] > nums[l])) {
        //         r = mid;
        //     } else if (nums[mid] > nums[r] || nums[mid] > nums[l]) {
        //         l = mid + 1;
        //     } else {
        //         r--;
        //         l++;
        //     }
        // }
        // return nums[l];
        
        int s = nums.size();
        int l = 0;
        int r = s - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r--; // move less aggressively just the right pointer; move left pointer will fail with the case [1, 2, 2] by missing the lowest int on the left
            }
        }
        return nums[l];
    }
};