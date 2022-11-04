// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
54_spiral_matrix LeetCode

Solution: 
    - directions array with total count checking
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // (0,0) -> (0,n-1) -> (m-1, n-1) -> (m-1, 0) -> (1, 0)
        // (1,0) -> (1,n-2) -> (m-2, n-2) -> (m-2, 1) -> (2, 1)
        // (2,1) -> (2,n-3) -> (m-3, n-3) -> (m-3, 2) -> (3, 2)
        // [1,2,3,4]
        // [1,2,3,4]
        // [1,2,3,4]
        // [1,2,3,4]
        // [1,2,3,4]
        if (matrix.empty()) {
            // return vector<int>();
            return {}; // empty vector
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        int count = 0;
        vector<int> res;
        
        vector<pair<int, int>> dir{{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> c_limit{n, m-1, n-1, m-2};
        int cur = 0;
        int c = 0;
        int i = 0; 
        int j = 0;
        while (count < total) {
            res.push_back(matrix[i][j]);
            ++count;
            ++c;
            if (c == c_limit[cur]) {
                c_limit[cur] -= 2;
                cur = (cur + 1) % 4;
                c = 0;
            }
            i += dir[cur].first;
            j += dir[cur].second;
        }
        return res;    
    }
};