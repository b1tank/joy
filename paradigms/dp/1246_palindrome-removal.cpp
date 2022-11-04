// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1246_palindrome-removal LeetCode

Solution: 
    - dp: recursively divide into subproblems 
    - O(N^3)
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        // 7 8 1 7 4 5 3 1 4
        // # @
        //   # @
        //     # @
        //       #
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i=0; i < n-1; i++) {
            dp[i][i] = 1;
            dp[i][i+1] = arr[i] == arr[i+1] ? 1 : 2;
        }
        dp[n-1][n-1] = 1;
        
        for (int i = n-3; i >= 0; i--) {
            for (int j = i+2; j < n; j++) {
                int tmp = dp[i+1][j] + 1;
                for (int k = i+2; k < j; k++) {
                    if (arr[k] == arr[i]) {
                        tmp = min(tmp, dp[i+1][k-1]+dp[k+1][j]);
                    }
                }
                if (arr[i] == arr[i+1]) tmp = min(tmp, dp[i+2][j] + 1); // left edge case
                if (arr[i] == arr[j]) tmp = min(tmp, dp[i+1][j-1]); // right edge case
                dp[i][j] = tmp;
            }
        }
        return dp[0][n-1];
    }
};