// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
207_course-schedule LeetCode

Solution: 
    - convert Graph edges to adjacency list
    - topological sort 
        - compute in-degrees
        - queue
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<vector<int>> graph(numCourses); // adjacency list
        vector<int> in_degree(numCourses, 0);

        // construct graph and compute in-degrees
        for (auto &p: prerequisites) {
            graph[p.second].push_back(p.first);
            in_degree[p.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) 
                q.push(i);
        }

        // Topological sort
        while (!q.empty()) {
            int cur = q.front(); 
            q.pop(); 
            numCourses--;
            for (auto& n : graph[cur]) {
                in_degree[n]--;
                if (in_degree[n] == 0) 
                    q.push(n);
            }
        }

        return numCourses == 0;
    }
};