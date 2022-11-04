// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
103_binary-tree-zigzag-level-order-traversal LeetCode

Solution: 
    - BFS (deque rather than queue)
    - DFS (recursive) (potentially O(logN) space for auto-cast enabled language like Java, Python)
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void dfs(TreeNode* cur, int level, vector<deque<int>>& v_dq) { // use reference !!!!
        
        int n = v_dq.size();
        if (level >= n) {
            deque<int> v{cur->val};
            v_dq.push_back(v);
        } else {
            if (level % 2 == 0) {
                v_dq[level].push_back(cur->val);
            } else {
                v_dq[level].push_front(cur->val);
            }
        }
        if (cur->left) {
            dfs(cur->left, level+1, v_dq);
        }
        if (cur->right) {
            dfs(cur->right, level+1, v_dq);
        }
        
        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        vector<deque<int>> res_dq;
        dfs(root, 0, res_dq);
        for (auto i = 0; i < res_dq.size(); ++i) {
            vector<int> tmp(res_dq[i].begin(), res_dq[i].end());
            res.push_back(tmp);
        }
        return res;
        
        // vector<vector<int>> res;
        // if (root == nullptr) return res;
        // deque<TreeNode*> dq;
        // dq.push_back(root);
        // bool left2right = true;
        // int count = 0;
        // int level = dq.size();
        // vector<int> tmp;
        // TreeNode* cur{nullptr};
        // while (!dq.empty()) {
        //     cur = left2right ? dq.front() : dq.back();
        //     if (left2right) {
        //         dq.pop_front();
        //         if (cur->left) dq.push_back(cur->left);
        //         if (cur->right) dq.push_back(cur->right);
        //     } else {
        //         dq.pop_back();
        //         if (cur->right) dq.push_front(cur->right);
        //         if (cur->left) dq.push_front(cur->left);
        //     }
        //     tmp.push_back(cur->val);
        //     ++count;
        //     if (count == level) {
        //         res.push_back(tmp);
        //         tmp.clear();
        //         count = 0;
        //         level = dq.size();
        //         left2right = !left2right;
        //     }
        // }
        // return res;
    }
};