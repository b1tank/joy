// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
235_lowest-common-ancestor-of-a-binary-search-tree LeetCode

Solution: 
    - recursive
    - iterative
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur{root};
        while (cur) {
            if (p->val == cur->val || q->val == cur->val) return cur;
            if ((p->val - cur->val) * (q->val - cur->val) < 0) return cur;
            if (p->val > cur->val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return nullptr;
        // if (p->val == root->val || q->val == root->val) {
        //     return root;
        // } else if ((p->val - root->val) * (q->val - root->val) < 0) {
        //     return root;
        // } else if (p->val > root->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // } else {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
    }
};