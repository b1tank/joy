// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
2_add-two-numbers LeetCode

Solution: 
    - dummy head
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 8, 4
        // 4, 7, 9
        ListNode* cur1{l1};
        ListNode* cur2{l2};
        ListNode* head = new ListNode();
        ListNode* cur{head};
        int carry = 0;
        int s = 0;
        while (cur1 || cur2) {
            s = carry;
            if (cur1) {
                s += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2) {
                s += cur2->val;
                cur2 = cur2->next;
            }
            carry = s / 10;
            cur->next = new ListNode(s % 10);
            cur = cur->next;
        }
        if (carry == 1) {
            cur->next = new ListNode(1);
        }
        return head->next; 
    }
};