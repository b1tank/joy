// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
33_search-in-rotated-sorted-array LeetCode

Solution: 
    - empty array check
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = nums.size();
        int l = 0; 
        int r = s - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > nums[r]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[r]) {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        return s > 0 && nums[l] == target ? l : -1;
    }
};