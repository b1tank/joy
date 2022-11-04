// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
98_validate-binary-search-tree LeetCode

Solution: 
    - recursive
    - iterative (in-order traversal)
*/

#include <iostream>
#include <stack>
#include <string>

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
public:
    bool isValidBST(TreeNode* root) {
        
        stack<TreeNode*> st;
        
        TreeNode* cur{root};
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        
        bool res = true;
        TreeNode* prev{nullptr};
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            res &= prev == nullptr ? true : tmp->val > prev->val;
            if (!res) return res;
            prev = tmp;
            cur = tmp->right;
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
        }
        return res;


        // if (root == nullptr) {
        //     return true;
        // }
        // bool res = true;
        // if (root->left) {
        //     TreeNode* cur = root->left;
        //     while (cur) {
        //         res &= cur->val < root->val;
        //         cur = cur->right;
        //     }
        //     if (!res) { return res; }
        //     res &= isValidBST(root->left);
        //     if (!res) { return res; }
        // }
        // if (root->right) {
        //     TreeNode* cur = root->right;
        //     while (cur) {
        //         res &= cur->val > root->val;
        //         cur = cur->left;
        //     }
        //     if (!res) { return res; }
        //     res &= isValidBST(root->right);
        //     if (!res) { return res; }
        // }
        // return res;
    }
};