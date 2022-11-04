// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
240_search-a-2d-matrix-ii LeetCode

Solution: 
    - binary search for every diagonal (O(lg(n!)) < O(nlg(n)))
    - divide and conquer (4 sub-matrices, O(nlg(n)))
        - find partition point (either linear or binary search) and look at 2 sub-matrics
            - matrix[row][mid]
        - look at 3 sub-matrices like below
    - choose the proper starting point and search (O(n + m))
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool searchHelper(const vector<vector<int>>& matrix, int lm, int ln, int rm, int rn, int target) {
        if (lm > rm || ln > rn) return false;
        if (lm == rm && ln == rn) return matrix[lm][ln] == target; // has to be added for terminating recursion !!!
        int mid_m = lm + (rm - lm) / 2;
        int mid_n = ln + (rn - ln) / 2;
        if (matrix[mid_m][mid_n] == target) return true;
        if (matrix[mid_m][mid_n] < target) {
            return  searchHelper(matrix, mid_m+1, ln, rm, mid_n, target)
                 || searchHelper(matrix, lm, mid_n+1, mid_m, rn, target) 
                 || searchHelper(matrix, mid_m+1, mid_n+1, rm, rn, target);
        } else {
            return  searchHelper(matrix, mid_m, ln, rm, mid_n-1, target)
                 || searchHelper(matrix, lm, mid_n, mid_m-1, rn, target) 
                 || searchHelper(matrix, lm, ln, mid_m-1, mid_n-1, target);
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // if (empty(matrix) || empty(matrix[0])) return false;
        // int m = matrix.size();
        // int n = matrix[0].size();
        // return searchHelper(matrix, 0, 0, m-1, n-1, target);
        
        if (empty(matrix) || empty(matrix[0])) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = m-1;
        int y = 0; 
        while (x >= 0 && x < m && y >= 0 && y < n) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                y++;
            } else {
                x--;
            }
        }
        return false;
    }
};