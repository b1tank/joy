// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
125_word-ladder LeetCode

Solution: 
    - BFS
        - keep track of level/depth: use queue size in a for loop; can add level together with val in the queue
        - string with a char being replaced in place (much faster than substr concatenation)
        - visited set
    - two-end bidirectional BFS
        - set for head and tail
        - *phead *ptail for optimizing smaller head
        - set s_tmp for updating frontier
        - visited set
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

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // check if endWord in wordList
        unordered_set<string> wl(wordList.begin(), wordList.end()); 
        if (wl.find(endWord) == wl.end()) return 0;
        
        // two-end bidirectional BFS
        unordered_set<string> head{beginWord}, tail{endWord}, *phead, *ptail;
        unordered_set<string> visited{beginWord, endWord}; // wl.erase(cur) also works but is much slower !!!
        int level = visited.size();
        
        while (!head.empty() && !tail.empty()) {
            if (head.size() <= tail.size()) { // optimize head with smaller size
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }

            unordered_set<string> s_tmp; // next frontier with all new neighbors
            for (auto it = phead->begin(); it != phead->end(); it++) {
                string cur = *it;
                for (int i = 0; i < cur.size(); i++) {
                    char tmp = cur[i];
                    for (int j = 0; j < 26; j++) {
                        cur[i] = 'a' + j; // replace char in original string; faster than substr concatenation

                        if (ptail->find(cur) != ptail->end()) {
                            return level;
                        }
                        
                        if (wl.find(cur) != wl.end() && visited.find(cur) == visited.end()) {
                            visited.insert(cur);
                            s_tmp.insert(cur);
                        }
                    }
                    cur[i] = tmp;
                }
            }
            
            level++;
            phead->swap(s_tmp); // update frontier
        }
        return 0;

        // check if endWord in wordList
        //unordered_set<string> wl(wordList.begin(), wordList.end());
        //if (wl.find(endWord) == wl.end()) return 0;
        
        //// BFS
        //queue<string> q;
        //q.push(beginWord);
        //unordered_set<string> visited{beginWord}; // wl.erase(cur) also works but is much slower !!!
        //int level = 1;
        //while (!q.empty()) {
        //    int n = q.size(); // must store the size here because the size will change in the inner loop
        //    for (int k = 0; k < n; k++) { // leverage current queue size to keep track of level/depth
        //        string cur = q.front();
        //        q.pop();
        //        wl.erase(cur);

        //        if (cur == endWord) {
        //            return level;
        //        }

        //        // find all neighbors - if not visted, add in queue
        //        for (int i = 0; i < cur.size(); i++) {
        //            char tmp = cur[i];
        //            for (int j = 0; j < 26; j++) {
        //                cur[i] = 'a' + j; // replace char in original string; faster than substr concatenation
        //                if (wl.find(cur) != wl.end() && visited.find(cur) == visited.end()) {
        //                    visited.insert(cur);
        //                    q.push(cur);
        //                }
        //            }
        //            cur[i] = tmp;
        //        }
        //    }
        //    level++;
        //}
        //return 0;
    }
};