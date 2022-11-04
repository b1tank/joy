// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
986_interval-list-intersections LeetCode

Solution: 
    - Two pointers
    - use min/max creatively
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int i = 0;
        int m = A.size();
        int j = 0;
        int n = B.size();
        vector<vector<int>> res;
        while (i < m && j < n) {
            int left = max(A[i][0], B[j][0]);
            int right = min(A[i][1], B[j][1]);
            if (left <= right) {
                vector<int> v{left, right};
                res.push_back(v);
            }
            if (A[i][1] > B[j][1]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
        
        // int i = 0;
        // int m = A.size();
        // int j = 0;
        // int n = B.size();
        // vector<vector<int>> res;
        // while (i < m && j < n) {
        //     vector<int> va = A[i];
        //     vector<int> vb = B[j];
        //     if (va[1] < vb[0]) {
        //         ++i;
        //     } else if (va[0] > vb[1]) {
        //         ++j;
        //     } else if (va[1] >= vb[0] && vb[0] >= va[0]) {
        //         if (va[1] < vb[1]) {
        //             vector<int> v{vb[0], va[1]};
        //             res.push_back(v);
        //             ++i;
        //         } else {
        //             vector<int> v{vb[0], vb[1]};
        //             res.push_back(v);
        //             ++j;
        //         }
        //     } else if (vb[1] >= va[0] && va[0] >= vb[0]) {
        //         if (vb[1] < va[1]) {
        //             vector<int> v{va[0], vb[1]};
        //             res.push_back(v);
        //             ++j;
        //         } else {
        //             vector<int> v{va[0], va[1]};
        //             res.push_back(v);
        //             ++i;
        //         }
        //     }
        // }
        // return res;
    }
};