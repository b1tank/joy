// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
99_recover-binary-search-tree LeetCode

Solution: 
    - iterative or recursive inorder traversal
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
    void recoverTree(TreeNode* root) {
        //       4
        //    2.    7
        //.  1. 3 5.  8
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur{root};
        while (cur->left) {
            st.push(cur->left);
            cur = cur->left;
        }
        vector<TreeNode*> candidates;
        TreeNode* prev{nullptr};
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            
            if (prev != nullptr && cur->val < prev->val) {
                if (candidates.empty()) {
                    candidates.push_back(prev);
                    candidates.push_back(cur);
                } else {
                    int tmp = candidates[0]->val;
                    candidates[0]->val = cur->val;
                    cur->val = tmp;
                    return;
                }
            };
            prev = cur;
            
            if (cur->right) {
                cur = cur->right;
                st.push(cur);
                while (cur->left) {
                    st.push(cur->left);
                    cur = cur->left;
                }
            }
        }
        int tmp = candidates[0]->val;
        candidates[0]->val = candidates[1]->val;
        candidates[1]->val = tmp;
        return;
    }
};