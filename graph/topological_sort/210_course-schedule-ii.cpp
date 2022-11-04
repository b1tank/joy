// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
210_course-schedule-ii LeetCode

Solution: 
    - convert Graph edges to adjacency list
    - topological sort 
        - compute in-degrees
        - queue
*/

#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<vector<int>> graph(numCourses); // adjacency list
        vector<int> in_degree(numCourses, 0);
        vector<int> res;

        // construct graph and compute in-degrees
        for (auto &p: prerequisites) {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++; 
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i); res.push_back(i);
            }
        }

        // Topological sort
        while (!q.empty()) {
            int cur = q.front(); 
            q.pop();
            for (auto& n: graph[cur]) {
                in_degree[n]--;
                if (in_degree[n] == 0) {
                    q.push(n); 
                    res.push_back(n);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};