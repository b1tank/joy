// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
160_intersection-of-two-linked-lists LeetCode

Solution: 
    - end-to-head circle (length intersection)
    - hashset
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* curA{headA};
        ListNode* curB{headB};
        while (curA != curB) {
            curA = curA == nullptr ? headB : curA->next;
            curB = curB == nullptr ? headA : curB->next;
        }
        return curA;
    }
};