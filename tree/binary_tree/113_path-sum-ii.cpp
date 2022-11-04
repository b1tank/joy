// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
113_path-sum-ii LeetCode

Solution: 
    - DFS recursion
*/

#include <iostream>
#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()
#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0)
#include <cstdlib> // rand() % 100 + 1
#include <vector>
#include <forward_list> // singly-linked list
#include <list> // doubly-linked list
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

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void pathSumHelper(TreeNode* cur, int sum, vector<int> path, vector<vector<int>>& res) { // don't use reference for path !!!
        //  5 
        // 4 3
        // sum == 9
        if (cur->left == nullptr && cur->right == nullptr) {
            if (sum == cur->val) {
                path.push_back(sum); // path is modified here, so it's better not use reference
                res.push_back(path);
            }
            return;
        }
        
        path.push_back(cur->val);

        if (cur->left) {
            pathSumHelper(cur->left, sum - cur->val, path, res);
        }
        if (cur->right) {
            pathSumHelper(cur->right, sum - cur->val, path, res);
        }
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        pathSumHelper(root, sum, vector<int>(), res);
        return res;
    }
};