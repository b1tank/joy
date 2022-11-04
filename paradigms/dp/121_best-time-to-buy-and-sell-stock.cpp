// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
121_best-time-to-buy-and-sell-stock LeetCode

Solution: 
    - One-pass
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (empty(prices)) return 0;
        int min_cur = prices[0];
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            int profit = prices[i] - min_cur;
            if (profit > max_profit) {
                max_profit = profit;
            }
            if (prices[i] < min_cur) {
                min_cur = prices[i];
            }
        }
        return max_profit;
    }
};