// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
73_set-matrix-zeroes LeetCode

Solution: 
    - In-place: use first row or col as flags
*/

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // [
        //   [0,1,2,0],
        //   [3,4,2,4],
        //   [0,4,1,0]
        // ]
        // [
        //   [1,1,2],
        //   [1,0,2],
        // ]
        // (i, j) marks (i, 0), (0, j)
        int m = matrix.size();
        int n = matrix[0].size();
        
        // check if 0 in the first row and col
        bool row0 = false;
        bool col0 = false;
        for (auto i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for (auto j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        
        // use first row and col as flags
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // label each cell from 2nd row and col
        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // assign zeros to first row or col
        if (row0) {
            for (auto j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col0) {
            for (auto i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        
        return;
    }
};