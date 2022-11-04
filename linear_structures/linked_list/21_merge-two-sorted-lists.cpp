// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
21_merge-two-sorted-lists LeetCode

Solution: 
    - dummy head
*/

#include <iostream>
#include <vector>
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1{l1};
        ListNode* cur2{l2};
        ListNode* head = new ListNode();
        ListNode* cur{head};
        while (cur1 || cur2) {
            if (cur1 && cur2) {
                if (cur1->val > cur2->val) {
                    cur->next = new ListNode(cur2->val);
                    cur2 = cur2->next;
                } else {
                    cur->next = new ListNode(cur1->val);
                    cur1 = cur1->next;
                }
            } else if (cur1) {
                cur->next = new ListNode(cur1->val);
                cur1 = cur1->next;
            } else if (cur2) {
                cur->next = new ListNode(cur2->val);
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        return head->next;
    }
};