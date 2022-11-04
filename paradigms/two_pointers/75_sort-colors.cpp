// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
75_sort-colors LeetCode

Solution: 
    - partition like quicksort
    - two pointers (+ middle current pointer)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    // void swap(vector<int>& nums, int i, int j) {
    //     int tmp = nums[i];
    //     nums[i] = nums[j];
    //     nums[j] = tmp;
    //     return;
    // }
    // void bubbleSort(vector<int>& nums, int i, int j, int k) {
    //     if (nums[i] > nums[j]) {
    //         swap(nums, i, j);
    //     }
    //     if (nums[j] > nums[k]) {
    //         swap(nums, j, k);
    //     }
    //     if (nums[i] > nums[j]) {
    //         swap(nums, i, j);
    //     }
    //     return;
    // }
public:
    void sortColors(vector<int>& nums) {
        // int s = nums.size();
        // 
        // int l = 0; 
        // int r = s-1; 
        // while (l < s && nums[l] == 0) {
        //     l++;
        // }
        // while (r >= 0 && nums[r] == 2) {
        //     r--;
        // }
        // int cur = l;
        // while (cur <= r) {
        //     bubbleSort(nums, l, cur, r);
        //     while (l < s && nums[l] == 0) {
        //         l++;
        //     }
        //     while (r >= 0 && nums[r] == 2) {
        //         r--;
        //     }
        //     if (l > cur) {
        //         cur = l;
        //     } else if (nums[l] <= nums[cur] && nums[cur] <= nums[r]) {
        //         cur++;
        //     }
        // }
        // return;
        
        int s = nums.size();
        
        int l = 0; 
        int r = s-1; 
        int cur = l;
        while (cur <= r) {
            if (nums[cur] == 0) {
                swap(nums[l], nums[cur]);
                l++;
                cur++; // only 0-0 and 1-0 swaps are possible (there is no 2 before the cur pointer because all 2s must have been swapped to the end)
            } else if (nums[cur] == 2) {
                swap(nums[r], nums[cur]);
                r--; // don't increment cur because there might be some zero which was just swapped to cur !!!
            } else {
                cur++;
            }
        }
        return;
    }
};