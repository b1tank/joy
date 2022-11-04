// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
92_reverse-linked-list-ii LeetCode

Solution: 
    - leverage a dummy head
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // prev(p) cur
        // 1    -> 2 -> 3 -> 4 -> 5 -> NULL
        // i == 2;
        
        int i = 1;
        ListNode* cur{head};
        ListNode* tmp_head = new ListNode(0, head); // dummy head
        ListNode* prev{tmp_head};
        
        // find the m position
        while (i != m) {
            prev = cur;
            cur = cur->next;
            ++i;
        }
        
        ListNode* m_ptr{cur}; // store m position pointer
        ListNode* pv{prev};
        ListNode* nt{nullptr};
        
        while (i <= n) {
            nt = cur->next;
            cur->next = pv;
            pv = cur;
            cur = nt;
            ++i;
        }
        
        // close the gaps
        prev->next = pv;
        m_ptr->next = cur;
        
        return tmp_head->next;
        
    }
};