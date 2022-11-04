// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
42_trapping-rain-water LeetCode

Solution: 
    - DP
    - stack
    - two pass (implemented)
    - one pass
*/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int mi = 0;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (height[i] >= m) {
                mi = i;
                m = height[i];
            }
        }
        
        int res = 0;
        
        int cm = 0;
        for (int i = 0; i <= mi; ++i) {
            if (height[i] >= cm) {
                cm = height[i];
            } else { 
                res += cm - height[i];
            }
        }
        cm = 0;
        for (int i = n-1; i >= mi; --i) {
            if (height[i] >= cm) {
                cm = height[i];
            } else { 
                res += cm - height[i];
            }
        }
        return res;
    }
};