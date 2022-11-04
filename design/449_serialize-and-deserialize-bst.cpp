// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
449_serialize-and-deserialize-bst LeetCode

Solution: 
    - queue
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/93167/Concise-C%2B%2B-19ms-solution-beating-99.4
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        preorderDFS(root, ret);
        return ret;
    }
    
    inline void preorderDFS(TreeNode* root, string& ret) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) ret.push_back(buf[i]);
        preorderDFS(root->left, ret);
        preorderDFS(root->right, ret);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
    
    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* root = new TreeNode(value);
        pos += sizeof(int);
        root->left = reconstruct(buffer, pos, minValue, value);
        root->right = reconstruct(buffer, pos, value, maxValue);
        return root;
    }
};

// class Codec {
//     string join(vector<string> v_str, const char delimiter) {
//         if (empty(v_str)) return "";
//         ostringstream oss;
//         if (!empty(v_str)) {
//             oss << *v_str.begin();
//         }
//         for (auto i = v_str.begin()+1; i != v_str.end(); i++) {
//             oss << delimiter << *i;
//         }
//         return oss.str();
//         
//         // if (empty(v_str)) return "";
//         // string ret = v_str[0];
//         // for (int i = 1; i < v_str.size(); i++) {
//         //     ret += delimiter + v_str[i]; 
//         // }
//         // return ret;
//     }
// 
// public:
// 
//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         //  4
//         //   3
//         //  2 
//         // 1 5
//         
//         // queue: 4,*,3,2,*,1,5,*,*,*,*
//         vector<string> v_str;
//         queue<TreeNode*> dq;
//         dq.push(root);
//         while (!dq.empty()) {
//             TreeNode* cur = dq.front();
//             dq.pop();
//             if (cur != nullptr) {
//                 dq.push(cur->left);
//                 dq.push(cur->right);
//                 v_str.push_back(to_string(cur->val));
//             } else {
//                 v_str.push_back("*");
//             }
//         }
//         string ret = join(v_str, ',');
//         return ret;
// 
//         // stack: 4,*,3,2,1,*,*,5,*,*,*
//     }
// 
//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         // queue
//         TreeNode* root(nullptr);
//         stringstream ss(data);
//         string str;
//         if (getline(ss, str, ',')) {
//             if (str == "*") return root;
//             root = new TreeNode(stoi(str));
//             queue<TreeNode*> dq;
//             dq.push(root);
//             while (!dq.empty()) {
//                 TreeNode* cur = dq.front();
//                 dq.pop();
//                 if (getline(ss, str, ',')) {
//                     cout << "l = " << str << endl;
//                     if (str != "*") {
//                         cur->left = new TreeNode(stoi(str));
//                         dq.push(cur->left);
//                     }
//                 }
//                 if (getline(ss, str, ',')) {
//                     cout << "r = " << str << endl;
//                     if (str != "*") {
//                         cur->right = new TreeNode(stoi(str));
//                         dq.push(cur->right);
//                     }
//                 }
//             }
//         }
//         return root;
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));