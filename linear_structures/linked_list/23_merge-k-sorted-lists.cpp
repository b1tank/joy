// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
23_merge-k-sorted-lists LeetCode

Solution: 
    - priority queue
        - max heap by default for cpp
        - min heap using greater<> compare struct
    - divide and conquer (merge pairs of two lists every iteration; O(1) space)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef pair<int, int> pi;

struct compare {
    bool operator()(const pi& pi1, const pi& pi2) {
        return pi1.first > pi2.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap with out-of-box greater<> compare struct
        // priority_queue<pi, vector<pi>, greater<pi>> pq; // use typedef to save some typing
        priority_queue<pi, vector<pi>, compare> pq; // min heap with custom compare struct
        vector<ListNode*> curs(lists.begin(), lists.end()); // initialize from another vector (https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/)
        for (auto i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) { // for corner case No.1: [[], [2,3]]
                pq.push(make_pair(lists[i]->val, i)); // no need to use pair actually -- push ListNode* in queue instead !!!
            }
        }
        ListNode* head = new ListNode();
        ListNode* cur{head};
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop(); // do pop() as soon as the top() is not needed !!
            cur->next = new ListNode(top.first);
            cur = cur->next;
            curs[top.second] = curs[top.second]->next;
            if (curs[top.second]) {
                pq.push(make_pair(curs[top.second]->val, top.second));
            }
        }
        return head->next;
    }
};