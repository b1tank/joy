// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
4_median-of-two-sorted-arrays LeetCode

Solution: 
    - small and large vectors
    - invariant: half_total
    - edge cases
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    double findMedianHelper(vector<int>& v_small, vector<int>& v_large) {
        int m = v_small.size();
        int n = v_large.size();
        bool even = (m+n) % 2 == 0;
        int l_small = 0;
        int r_small = m;
        int half_total = (m+n+1) / 2;
        while (l_small <= r_small) {
            int mid_small = l_small + (r_small - l_small) / 2;
            int mid_large = half_total - mid_small;
            if (mid_small < r_small && v_small[mid_small] < v_large[mid_large-1]) {
                l_small = mid_small + 1;
            } else if (mid_small > l_small && v_small[mid_small-1] > v_large[mid_large]) {
                r_small = mid_small - 1;
            } else {
                int max_left = 0;
                if (mid_small == 0) {
                    max_left = v_large[mid_large-1];
                } else if (mid_large == 0) {
                    max_left = v_small[mid_small-1];
                } else {
                    max_left = max(v_small[mid_small-1], v_large[mid_large-1]);
                }
                if (!even) { return max_left;}
                
                int min_right = 0;
                if (mid_small == m) {
                    min_right = v_large[mid_large];
                } else if (mid_large == n) {
                    min_right = v_small[mid_small];
                } else {
                    min_right = min(v_small[mid_small], v_large[mid_large]);
                }
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // m1, m2, m3, ... , mk
        // n1, n2, n3, ... , nk
        // 1 2 3 4 5
        //   2 8 8 9
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianHelper(nums2, nums1);
        } else {
            return findMedianHelper(nums1, nums2);
        }
    }
}