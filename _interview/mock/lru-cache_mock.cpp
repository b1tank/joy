// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
// 
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

#include <iostream>
1 2
1 2

data: 3 
put(1, 'a')
put(2, 'b')
put(3, 'c')
put(4, 'd')

// data : 2 - b 3 -c 4 -d 
put(2, 'd')
// data : 3 -c 4 -d 2 - d
put(5, 'e')

// data : 4 - d 2 - d 5 - e 
// pop front
// pop front append back
// linkedlist 

class ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
public:
    ListNode(int n) : val(n), prev(nullptr), next(nullptr) {
    }
};

class LRUCache {
    unordered_map<int, ListNode*> hm;
    ListNode* head, tail;
    int capacity;

public:

    LRUCache(int n) : capacity(n), head(nullptr), tail(nullptr) { }

    // put(1, 'a')
    // put(2, 'b')
    // put(3, 'c')

    // put(4, 'd')

    // // data : head 2b -> 4d -> 3c -> null

    // get(3)
    // return 'c'
    // put(4, 'e')
    // get(5)
    int get(int key) {
        if (hm.find(key) != hm.end()) {
            ListNode* cur = hm[key];
            remove(cur);
            append(cur);
            return hm[key]->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hm.size() == capacity) {
            if (hm.find(key) != hm.end()) {
                ListNode* cur = hm[key];
                remove(cur);
                append(cur);
            } else {
                ListNode* cur = new ListNode(value);
                remove(head); // LRU
                append(cur);
            }
        } else {
            ListNode* cur = new ListNode(value);
            // append to linked list
            tail->next = cur;
            tail = cur;
            hm[key] = cur;
        }
    }

    void remove(ListNode* cur) {
        // 2 -> 4
        if (cur->prev == nullptr) {
            head = head->next;
            head->prev = nullptr;
        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
    }

    void append(ListNode* cur) {
        tail->next = cur;
        cur->prev = tail;
        tail = cur;
    }

};
