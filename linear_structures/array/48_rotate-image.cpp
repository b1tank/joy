// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
48_rotate-image LeetCode

Solution: 
    - transpose and reverse
    - reverse and diagonal swap
    - rotate layer by layer
*/

#include <vector>
using namespace std;

class Solution {
    // void rotate_layer(vector<vector<int>>& matrix, int start, int end) {
    //     for (auto i = 0; i < end-start; ++i) { // Don't
    //         int tmp = matrix[start][start+i];
    //         matrix[start][start+i] = matrix[end-i][start];
    //         matrix[end-i][start] = matrix[end][end-i];
    //         matrix[end][end-i] = matrix[start+i][end];
    //         matrix[start+i][end] = tmp;
    //     }
    //     return;
    // }
    void reverse(vector<int>& v) {
        int i = 0;
        int j = v.size()-1;
        while (i < j) {
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            ++i;
            --j; 
        }
        return;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // [a,b,c,d,e]
        
        // [x,b,x,x,a]
        // [x,x,x,x,b]
        // [x,x,x,x,c]
        // [x,x,x,x,d]
        // [x,x,x,x,e]
                   
        // rotate layer by layer
        // int i = 0;
        // int j = matrix.size()-1;
        // while (i < j) {
        //     rotate_layer(matrix, i++, j--);
        // }
        // return;
        
        // reverse all vectors
        int n = matrix.size();
        for (auto i = 0; i < n; ++i) {
            reverse(matrix[i]);
        }    
        // diagonal swap
        for (auto i = 0; i < n-1; ++i) {
            for (auto j = 0; j < n-1-i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = tmp;
            }
        }
        return;
    }
};