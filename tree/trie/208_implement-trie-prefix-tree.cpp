// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
208_implement-trie-prefix-tree LeetCode

Solution: 
    - use vector of 26 instead of unordered_map
    - use smart pointer instead of normal pointer with new/delete (destructor is needed)

*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class TrieNode {
public:
    // vector<TrieNode*> next;
    vector<shared_ptr<TrieNode>> next;
    bool isEnd;
    
    TrieNode() : next(26, nullptr), isEnd(false) {}
};
class Trie {
    // TrieNode* root;
    shared_ptr<TrieNode> root;
public:
    /** Initialize your data structure here. */
    Trie() {
        // root = new TrieNode();
        root = make_shared<TrieNode>();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // TrieNode* cur = root;
        shared_ptr<TrieNode> cur = root;
        for (char c: word) {
            if (cur->next[c - 'a'] == nullptr) {
                // cur->next[c - 'a'] = new TrieNode();
                cur->next[c - 'a'] = make_shared<TrieNode>();
            }
            cur = cur->next[c - 'a'];
        }
        cur->isEnd = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // TrieNode* cur = root;
        shared_ptr<TrieNode> cur = root;
        for (char c : word) {
            if (cur->next[c - 'a'] == nullptr) {
                return false;
            } else {
                cur = cur->next[c - 'a'];
            }
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // TrieNode* cur = root;
        shared_ptr<TrieNode> cur = root;
        for (char c : prefix) {
            if (cur->next[c - 'a'] == nullptr) {
                return false;
            } else {
                cur = cur->next[c - 'a'];
            }
        }
        return true;
    }
    
// public:
//     char val;
//     unordered_map<char, TrieNode*> next;
//     bool isEnd;
//     
//     TrieNode(char c) {
//         val = c;
//         isEnd = false;
//     }
// };
// class Trie {
//     TrieNode* root;
// public:
//     /** Initialize your data structure here. */
//     Trie() {
//         root = new TrieNode('*');
//     }
//     
//     /** Inserts a word into the trie. */
//     void insert(string word) {
//         TrieNode* cur = root;
//         for (char c: word) {
//             if (cur->next.find(c) == cur->next.end()) {
//                 cur->next[c] = new TrieNode(c);
//             }
//             cur = cur->next[c];
//         }
//         cur->isEnd = true;
//         return;
//     }
//     
//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         TrieNode* cur = root;
//         for (char c : word) {
//             if (cur->next.find(c) == cur->next.end()) {
//                 return false;
//             } else {
//                 cur = cur->next[c];
//             }
//         }
//         return cur->isEnd;
//     }
//     
//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string prefix) {
//         TrieNode* cur = root;
//         for (char c : prefix) {
//             if (cur->next.find(c) == cur->next.end()) {
//                 return false;
//             } else {
//                 cur = cur->next[c];
//             }
//         }
//         return true;
//     }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */