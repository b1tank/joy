// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
133_clone-graph LeetCode

Solution: 
    - use hashmap to find the reference in new cloned graph !
    - DFS (recursive)
    - BFS (queue)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node*, Node*> hm;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        hm[node] = new Node(node->val); // visited; also containing the node-to-copy relationship
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (auto n : cur->neighbors) {
                if (hm.find(n) == hm.end()) {
                    hm[n] = new Node(n->val);
                    q.push(n);
                }
                hm[cur]->neighbors.push_back(hm[n]); // must be out of the if block above !!!!
            }
        }
        return hm[node];
        
        // if (node == nullptr) {
        //     return nullptr;
        // }
        // if (hm.find(node) == hm.end()) {
        //     hm[node] = new Node(node->val);
        //     for (auto n : node->neighbors) {
        //         hm[node]->neighbors.push_back(cloneGraph(n));
        //     }
        // }
        // return hm[node];
    }
};