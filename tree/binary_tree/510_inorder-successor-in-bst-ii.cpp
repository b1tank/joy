// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
510_inorder-successor-in-bst-ii LeetCode

Solution: 
    - analyze case by case
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
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        //. 1 2 3 4(r) 5 7 8
        //         4
        //.    2.     7
        //   1. 3   5.  8
        // no left, no right => parent (parent's left), 
        
        if (node->right) {
            node = node->right;
            while (node->left) {
                node = node->left;
            }
            return node;
        } else {
            while (node->parent != nullptr && node->parent->right == node) {
                node = node->parent;
            }
            return node->parent;
        }
    }
};