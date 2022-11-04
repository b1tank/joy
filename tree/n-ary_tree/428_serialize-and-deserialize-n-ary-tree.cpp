// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
428_serialize-and-deserialize-n-ary-tree LeetCode

Solution: 
    - add number of children after parent 
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serialize_helper(res, root);
        return res;
    }
    
    void serialize_helper(string &res, Node *root) {

        if(!root) return;

        int n = root->children.size();
        res += " " +  to_string(root->val) + " " + to_string(n);

        for(auto& c : root->children) {
            serialize_helper(res, c);
        }
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }
    
    Node* deserialize_helper(stringstream &ss) {

        ss.peek(); // make empty stringstream reach EOF
        if(ss.eof()) return NULL;

        int val, size;
        auto node = new Node();
        ss >> node->val >> size;
        for(int i = 0; i < size; i++) 
            node->children.push_back(deserialize_helper(ss));
        return node;
    }

    // string serialize(Node* root) {
    //     //    1 
    //     //  3 2 4
    //     //   5 6
    //     // 1 [ 3 2 [ 5 6 ] 4 ]
    //     string res;
    //     if (root != nullptr) {
    //         res += to_string(root->val);
    //         if (!root->children.empty()) {
    //             res += " [";
    //             for (auto& c : root->children) {
    //                 res += " " + serialize(c);
    //             }
    //             res += " ]";
    //         }
    //     }
    //     return res;
    // }
	
    // // Decodes your encoded data to tree.
    // Node* deserialize(string data) {
    //     if (data.empty()) return nullptr;
    //     istringstream iss(data);
    //     string token;
    //     Node* dummy = new Node(0, vector<Node*>());
    //     Node* cur{dummy};
    //     stack<Node*> prev;
    //     // st: dummy; cur: 1
    //     // st: dummy,1; cur: 2
    //     // st: dummy,1,2; cur: 5
    //     while (iss >> token) {
    //         if (token == "[") {
    //             prev.push(cur);
    //             cur = cur->children.back();
    //         } else if (token == "]") {
    //             cur = prev.top();
    //             prev.pop();
    //         } else {
    //             int v = stoi(token);
    //             Node* n = new Node(v);
    //             cur->children.push_back(n);
    //         }
    //     }
    //     return dummy->children[0];
    // }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));