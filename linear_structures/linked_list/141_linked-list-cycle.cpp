// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
141_linked-list-cycle LeetCode

Solution: 
    - unordered_set
    - slow and fast two pointers
*/

#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // x -> y ->
        // i = r * 1
        // j = r * 2
        // ++r
        // r > x && r = n * y
        ListNode* slow{head};
        ListNode* fast{head};
        int step = 0;
        while (fast != nullptr && (step == 0 || step > 0  && slow != fast)) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            ++step;
        }
        return fast != nullptr;
    }
};