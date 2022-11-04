// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
7_reverse-integer LeetCode

Solution: 
    - modulo for negative: a%b = a - (a/b)*b
        - -123 % 10 = -123 - (-123/10)*10 = -3
        - 123 % -10 = -123 - (123/-10)*-10 = 3
    - INT_MAX = 2^31 - 1 (2147483647)
      INT_MIN = -2^31 (-2147483648)
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        
        while (x != 0) {
            int mod = x % 10;
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && mod > 7)) return 0;
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && mod < -8)) return 0;
            x /= 10;
            ret = ret * 10 + mod;
        }
        return ret;
        
        // if (x == INT_MIN) return 0;
        // int ret = 0;
        // bool negative = false;
        // if (x < 0) {
        //     x = 0 - x; // edge case (overflow): INT_MIN
        //     negative = true;
        // }
        // 
        // int mark = INT_MAX / 10;
        // 
        // while (x > 0) {
        //     int mod = x % 10;
        //     if (ret > mark || (!negative && ret == mark && mod > 7) || (negative && ret == mark && mod > 8)) {
        //         return 0;
        //     }
        //     ret = ret * 10 + mod;
        //     x = (x - mod) / 10;
        // }
        // return negative ? 0 - ret : ret;
    }
};