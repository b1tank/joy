// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
277_find-the-celebrity LeetCode

Solution: 
    - dynamically changing candidate rather than using set
        - every iteration, there is one candidate that would be ruled out !
    - cache mindset
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    unordered_map<pair<int, int>, bool> um;
    bool knowsFromCache(int a, int b) {
        pair<int, int> cur = make_pair(a, b);
        if (um.find(cur) != um.end()) {
            return um[cur];
        } else {
            bool ret = knows(a, b);
            um[cur] = ret;
            return ret;
        }
    }
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knowsFromCache(candidate, i)) {
                candidate = i;
            }
        }
        for (int j = 0; j < n; j++) {
            if (candidate == j) continue;
            if (knowsFromCache(candidate, j) || !knowsFromCache(j, candidate)) {
                return -1;
            }
        }
        return candidate;
        // unordered_set<int> cs;
        // for (int i=0; i < n; i++) {
        //     cs.insert(i);
        // }
        // while (!cs.empty()) {
        //     int cur = *cs.begin();
        //     bool isCelebrity = true;
        //     unordered_set<int> non_cs;
        //     for (int j=0; j < n; j++) {
        //         if (j != cur) {
        //             if (knows(cur, j) || !knows(j, cur)) {
        //                 // cur cannot be celebrity;
        //                 isCelebrity = false;
        //                 non_cs.insert(cur);
        //             } else if (!knows(cur, j) || knows(j, cur)) {
        //                 // cs[j] cannot be celebrity;
        //                 non_cs.insert(j);
        //             }
        //         }
        //     }
        //     if (isCelebrity) return cur;
        //     for (int e : non_cs) {
        //         cs.erase(e);
        //     }
        // }
        // return -1;
    }
};