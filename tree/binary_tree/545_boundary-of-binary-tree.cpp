// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
545_boundary-of-binary-tree LeetCode

Solution: 
    - simple approach (step by step)
    - edge case: root can be a leaf !!!
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

/**
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
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        vector<int> res;
        if(root == nullptr) return res;
        res.push_back(root->val);
        // add left boundary
        if (root->left != nullptr) {
            TreeNode* cur{root->left};
            while (cur) {
                if (cur->left || cur->right) res.push_back(cur->val);
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
        }
        // add all leaves (edge case: root is also a leaf !!!)
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
            if (cur->left == nullptr && cur->right == nullptr && cur != root) {
                res.push_back(cur->val);
            }
        }
        
        // add right boundary (in reverse order)
        vector<int> right_boundary;
        if (root->right) {
            TreeNode* cur{root->right};
            while (cur) {
                if (cur->left || cur->right) right_boundary.push_back(cur->val);
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
            }
        }
        res.insert(res.end(), right_boundary.rbegin(), right_boundary.rend());
        return res;
    }
};