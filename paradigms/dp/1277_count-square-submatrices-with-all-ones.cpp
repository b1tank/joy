// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1277_count-square-submatrices-with-all-ones LeetCode

Solution: 
    - DP (left-top)
    - DP (right-bottom) (reverse approach, more efficient)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int cal_max_a(vector<vector<int>> const & mat, int i, int j, vector<vector<int>>& dp) {
        if (mat[i][j] == 0) return 0;
        int init_a = 1;
        if (i-1 >= 0) {
            init_a = max(dp[i-1][j]-1, init_a);
        }
        if (j-1 >= 0) {
            init_a = max(dp[i][j-1]-1, init_a);
        }
        if (i-1 >= 0 && j-1 >= 0) {
            init_a = max(dp[i-1][j-1]-1, init_a);
        }
        
        int ii = init_a+i;
        int jj = init_a+j;
        int m = mat.size();
        int n = mat[0].size();
        int res = init_a;
        while (ii < m && jj < n) {
            int s = 0;
            for (auto v = j; v < jj; ++v) {
                s += mat[ii][v];
            }
            for (auto h = i; h < ii; ++h) {
                s += mat[h][jj];
            }
            s += mat[ii][jj];
            if (s == (ii-i)*2+1) {
                ++res;
                ++ii;
                ++jj;
            } else {
                break;
            }
        }
        
        dp[i][j] = res;
        return res;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (matrix[i][j] && i && j) {
                    matrix[i][j] = min(min(matrix[i-1][j-1], matrix[i-1][j]), matrix[i][j-1]) + 1;
                }
                res += matrix[i][j];
            }
        }
        return res;
        // int res = 0;
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,0));
        // for (auto i = 0; i < m; ++i) {
        //     for (auto j = 0; j < n; ++j) {
        //         res += cal_max_a(matrix, i, j, dp);
        //     }
        // }
        // return res;
        
    }
};
