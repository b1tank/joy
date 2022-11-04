// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
25_reverse-nodes-in-k-group LeetCode

Solution: 
    - pointers: flag, prev, cur, next
    - dummy head
*/

#include <iostream>
#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()
#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0)
#include <cstdlib> // rand() % 100 + 1
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set> // unordered_set, unordered_multiset
#include <set> // set, multiset
#include <unordered_map> // unordered_map, unordered_multimap
#include <map> // map, multimap
#include <utility> // pair<>
#include <tuple> // tuple<>
#include <algorithm> // reverse, sort, transform, find, remove, count, count_if
#include <memory> // shared_ptr<>, make_shared<>
#include <stdexcept> // invalid_argument

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //        1 -> 2 -> 3 -> 4 -> 5
        //   d -> 1 -> 2 -> 3 -> 4 -> 5
        // p prev c    n
        //   d -> 1    2 -> 3 -> 4 -> 5
        //.    <-   
        //        p    c    n
        //   d -> 1 <- 2    3 -> 4 -> 5
        //.    <-      p.   c.   n 
        //   d -> 2 -> 1 -> 3 -> 4 -> 5
        //.            p prev.   c.   n 
        
        if (k < 2) return head;
        ListNode* cur0{head};
        int n = 0;
        while (cur0) {
            cur0 = cur0->next;
            n++;
        }
        int times = n / k;
        ListNode* dummy = new ListNode(0, head);
        ListNode* flag{dummy};
        ListNode* prev{dummy};
        ListNode* cur{head};
        ListNode* next{head->next};
        for (int i = 0; i < times; i++) {
            for (int j = 0; j < k; j++) {
                cur->next = prev;
                prev = cur;
                cur = next;
                if (cur) next = cur->next;
            }
            
            ListNode* tmp{flag->next};
            flag->next->next = cur;
            flag->next = prev;
            
            flag = tmp;
            prev = tmp;
        }
        return dummy->next;
    }
};