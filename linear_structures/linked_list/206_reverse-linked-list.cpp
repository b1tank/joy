// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
206_reverse-linked-list LeetCode

Solution: 
    - recursive
    - swap-like logic
        - nullptr initialization (https://www.learncpp.com/cpp-tutorial/6-7a-null-pointers/)
*/

#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if (head == nullptr || head->next == nullptr) {
        //     return head;
        // }        
        // ListNode* new_head = reverseList(head->next);
        // ListNode* cur{new_head};
        // while (cur->next != nullptr) {
        //     cur = cur->next;
        // }
        // cur->next = head;
        // head->next = nullptr;
        // return new_head;

        // prev 1->2->3->4->NULL
        ListNode* prev{nullptr}; // must be initialized with nullptr; otherwise, it points to garbage address; https://www.learncpp.com/cpp-tutorial/6-7a-null-pointers/
        ListNode* n{nullptr};
        ListNode* cur{head};
        while (cur != nullptr) {
            n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }
};