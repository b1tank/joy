// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1377_frog-position-after-t-seconds LeetCode

Solution: 
    - BFS with counting steps/depth/length/level
    - edge case
        - more steps towards target's children (easy to miss !!!)
        - more steps at leaves
        - less steps for reaching target's level
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
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // t moves to target
        //      4
        //.   2.  5  7
        //. 1.  3.     8
        
        // t >= 2 target = 3 ---- 1/3 * 1/2 * 1 ... 
        // t == 1 target = 5 ---- 1/3
        // t == 20 target = 1 --- 1/3 * 1/2 * 1 ...
        // t == 1 target = 8 ---- 0
        
        // construct graph
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] < edges[i][1]) {
                graph[edges[i][0]].insert(edges[i][1]);
            } else {
                graph[edges[i][1]].insert(edges[i][0]);
            }
        }
        
        // BFS 
        queue<pair<int, double>> q;
        q.emplace(1, 1.0);
        
        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<int, double> p = q.front();
                q.pop();

                int nei_count = graph[p.first].size();
                if (p.first == target) {
                    if (steps == t || (steps < t && nei_count == 0)) {
                        return p.second;
                    } else {
                        return 0.0;
                    }
                }
                
                for (auto& nei : graph[p.first]) {
                    q.emplace(nei, p.second / nei_count);
                }
            }
            steps++;
            if (steps > t) {
                return 0.0;
            }
        }
        return 0.0;
    }
};