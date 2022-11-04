// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
918_maximum-sum-circular-subarray LeetCode

Solution: 
    - max&min subarray: (refer to 53_maximum-subarray)
        - greedy
        - in-place DP
    - DP (2-dimensional - inefficient O(n^2))
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int n = A.size();
        
        int total = A[0];
        int cur_max = A[0];
        int cur_min = A[0];
        int res_max = A[0];
        int res_min = A[0];
        
        for (auto i = 1; i < n; ++i) {
            cur_max = cur_max > 0 ? cur_max + A[i] : A[i]; // equivalent to max(cur_max + A[i], A[i])
            cur_min = cur_min > 0 ? A[i] : cur_min + A[i];
            res_max = max(res_max, cur_max);
            res_min = min(res_min, cur_min);
            total += A[i];
        }
        return res_max > 0 ? max(res_max, total - res_min) : res_max; // corner case
        
        // Inefficient DP O(n^2)
        //
        // // [3,-1,2,1]
        // // [3,-1,2,1,3,-1,2,1]
        // //   j 0 1 2 .. n-1
        // // i 0 y x x    x
        // //   1 y y x    x
        // //   2 x y y    x
        // //   .     y
        // //   . 
        // // n-1 x x x    y
        // 
        // int n = A.size();
        // int sm = accumulate(A.begin(), A.end(), 0);
        // vector<vector<int>> s(n, vector<int>(n, INT_MIN)); 
        // int res = sm;
        // 
        // // fill diagonal
        // for (auto i = 0; i < n; ++i) {
        //     s[i][i] = A[i];
        //     res = max(res, s[i][i]);
        // }
        // 
        // // fill upper triangle
        // for (auto i = 0; i < n-1; ++i) {
        //     for (auto j = i+1; j < n; ++j) {
        //         s[i][j] = s[i][j-1] + A[j];
        //         res = max(res, s[i][j]);
        //         if (s[i][j] != sm) {
        //             res = max(res, sm - s[i][j]);
        //         }
        //     }
        // }
        //     
        // // // fill lower triangle
        // // for (auto i = 1; i < n; ++i) {
        // //     for (auto j = 0; j < i; ++j) {
        // //         s[i][j] = i-j == 1 ? sm : sm - s[j+1][i-1];
        // //         res = max(res, s[i][j]);
        // //     }
        // // }
        //     
        // return res;
    }
};