// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
138_copy-list-with-random-pointer LeetCode

Solution: 
    - hashmap
    - "DNA" replication
        - for the original linked list: cut and splice
*/

#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (!head) return nullptr;

        Node* cur{head};

        // duplicate each node in chain
        while (cur) {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }

        // assign random link for each duplicated node
        cur = head;
        while (cur) {
            cur->next->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }

        // split the chain into two
        cur = head;
        Node* cur2 = head->next;
        Node* res = head->next;
        while (cur && cur->next) {
            cur->next = cur->next->next;
            cur = cur->next;
            if (cur2->next) {
                cur2->next = cur2->next->next;
                cur2 = cur2->next;
            }
        }
        return res;

        // Node* res = new Node(0);
        // unordered_map<Node*, Node*> m;
        //
        // Node* cur{head};
        // Node* cur_r{res};
        // while (cur != nullptr) {
        //     cur_r->next = new Node(cur->val);
        //     cur_r = cur_r->next;
        //     m[cur] = cur_r;
        //
        //     cur = cur->next;
        // }
        // cur = head;
        // cur_r = res->next;
        // while (cur != nullptr) {
        //     cur_r->random = m[cur->random];
        //     cur_r = cur_r->next;
        //     cur = cur->next;
        // }
        // return res->next;
    }
};
