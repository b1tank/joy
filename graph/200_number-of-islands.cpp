// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
200_number_of_islands LeetCode

Solution: 
    - DFS (space O(M*N))
    - BFS (space O(min(M,N)))
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '#';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
};