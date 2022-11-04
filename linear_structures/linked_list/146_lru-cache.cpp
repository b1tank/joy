// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
146_lru-cache LeetCode

Solution: 
    - linked hashmap is a hashmap whose values are pointers to the nodes in a linkedlist
    - use head and tail for easy management of linkedlist
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

struct Node {
    int key;
    int value;
    // Node* prev;
    // Node* next;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;
    Node(int key, int value) : key(key), value(value) {}
};
class LRUCache {
    int capa;
    // unordered_map<int, Node*> um;
    unordered_map<int, shared_ptr<Node>> um;
    // Node* head;
    // Node* tail;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
public:
    LRUCache(int capacity) {
        capa = capacity;
        // head = new Node(0, 0);
        // tail = new Node(0, 0);
        head = make_shared<Node>(0, 0);
        tail = make_shared<Node>(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (um.find(key) != um.end()) {
            removeNode(um[key]);
            insertToHead(um[key]);
            return um[key]->value;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (um.find(key) != um.end()) {
            removeNode(um[key]);
            insertToHead(um[key]);
            um[key]->value = value;
        } else {
            if (um.size() == capa) {
                // Node* cur = tail->prev;
                shared_ptr<Node> cur = tail->prev;
                removeNode(cur);
                um.erase(cur->key);
                // delete cur;
            }
            // Node* n = new Node(key, value);
            shared_ptr<Node> n = make_shared<Node>(key, value);
            insertToHead(n);
            um[key] = n;
        }
        return;
    }
    // void removeNode(Node* cur) {
    void removeNode(shared_ptr<Node> cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        return;
    }
    // void insertToHead(Node* cur) {
    void insertToHead(shared_ptr<Node> cur) {
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */