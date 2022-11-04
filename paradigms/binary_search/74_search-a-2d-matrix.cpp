// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
74_search-a-2d-matrix LeetCode

Solution: 
    - binary search
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int valueAt(const int rank, const vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        return matrix[rank / n][rank % n];
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int t = m * n;
        int l = 0;
        int r = t-1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int mid_val = valueAt(mid, matrix);
            if (mid_val == target) return true;
            if (mid_val > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return valueAt(l, matrix) == target;
    }
};