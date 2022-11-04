// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
134_gas-station LeetCode

Solution: 
    - one pass: return the index after the index where the lowest possible tank is reached (total gas >= total cost)
        - better draw graph to show the trend to understand the algorithm
*/

#include <iostream>
#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()
#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0)
#include <cstdlib> // rand() % 100 + 1
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set> // unordered_set, unordered_multiset
#include <set> // set, multiset
#include <unordered_map> // unordered_map, unordered_multimap
#include <map> // map, multimap
#include <utility> // pair<>
#include <tuple> // tuple<>
#include <algorithm> // reverse, sort, transform, find, remove, count, count_if
#include <memory> // shared_ptr<>, make_shared<>
#include <stdexcept> // invalid_argument

using namespace std;

class Solution {
    // bool can_circle(int i, vector<int>& gas, vector<int>& cost) {
    //     int num = 0;
    //     int n = gas.size();
    //     int tank = 0;
    //     while (num < n) {
    //         if (tank + gas[i] >= cost[i]) {
    //             tank = tank + gas[i] - cost[i];
    //             i = (i+1) % n;
    //             num++;
    //         } else {
    //             break;
    //         }
    //     }
    //     return num == n;
    // }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //  4 1 2 3
        //  2 4 3 1
        //0 2 -1 -2 0 
        // 
        //  3 1 1
        //  1 2 2
        //0 2 1 0
        
        // int n = gas.size();
        // for (int i = 0; i < n; i++) {
        //     if (can_circle(i, gas, cost)) {
        //         return i;
        //     }
        // }
        // return -1;
        
        int n = gas.size();
        int total_g = 0;
        int total_c = 0;
        int cur_tank = 0;
        int min_tank = INT_MAX;
        int min_tank_i = 0;
        for (int i = 0; i < n; i++) {
            total_g += gas[i];
            total_c += cost[i];
            
            cur_tank = cur_tank + gas[i] - cost[i];
            if (cur_tank <= min_tank) {
                min_tank = cur_tank;
                min_tank_i = i;
            }
        }
        if (total_g < total_c) {
            return -1;
        } else {
            return (min_tank_i + 1) % n;
        }
        
        
    }
};