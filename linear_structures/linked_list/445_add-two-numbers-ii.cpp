// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
445_add-two-numbers-ii LeetCode

Solution: 
    - stack: fit for reverse kind of logic !!!
    - dummy head
*/

#include <iostream>
#include <vector>
#include <stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        ListNode* cur1{l1};
        ListNode* cur2{l2};
        while (cur1 != nullptr) {
            s1.push(cur1->val);
            cur1 = cur1->next;
        }
        while (cur2 != nullptr) {
            s2.push(cur2->val);
            cur2 = cur2->next;
        }
        int carry = 0;
        int s = 0;
        ListNode* head = new ListNode();
        while (!s1.empty() || !s2.empty()) {
            s = carry;
            if (!s1.empty()) {
                s += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                s += s2.top();
                s2.pop();
            }
            ListNode* cur = new ListNode(s % 10, head->next);
            head->next = cur;
            carry = s / 10;
        }
        if (carry == 1) {
            ListNode* cur = new ListNode(1, head->next);
            head->next = cur;
        }
        
        return head->next;
    }
};