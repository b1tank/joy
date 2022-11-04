// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
126_word-ladder-ii LeetCode

Solution: 
    - BFS
        - new visited set for each level
    - DFS
        - add all paths to result
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
    void dfs (string& beginWord, string& curWord, unordered_map<string, unordered_set<string>>& prevs, vector<string>& path, vector<vector<string>>& res) {
        // if (curWord == beginWord) {
        //     vector<string> path_copy(path); // copy here
        //     path_copy.push_back(curWord);
        //     reverse(path_copy.begin(), path_copy.end());
        //     res.push_back(path_copy);
        //     return;
        // }
        
        // for (auto p : prevs[curWord]) { // auto& not work
        //     path.push_back(curWord);
        //     dfs(beginWord, p, prevs, path, res);
        //     path.pop_back();
        // }

        if (curWord == beginWord) {
            path.push_back(curWord);
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }
        
        path.push_back(curWord);
        for (auto p : prevs[curWord]) { // auto& not work
            vector<string> new_path(path); // why have to be new_path !!!
            dfs(beginWord, p, prevs, new_path, res);
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        if (wl.find(endWord) == wl.end()) { return {}; }
        
        unordered_map<string, unordered_set<string>> prevs;
        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        bool found_target = false;
        int cur_len = 1;
        while (!q.empty()) {
            unordered_set<string> new_visited; 
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string cur = q.front();
                q.pop();

                string prev{cur};
                for (int j = 0; j < prev.size(); j++) {
                    char c = cur[j];
                    for (int k = 0; k < 26; k++) {
                        cur[j] = k + 'a';
                        if (cur == endWord) {
                            prevs[cur].insert(prev);
                            found_target = true;
                        } else if (wl.find(cur) != wl.end() && visited.find(cur) == visited.end()) {
                            q.push(cur);
                            new_visited.insert(cur); // two nodes in the same level can point to the same neighbor in the next level; hence, don't add neighbors for a node to visited before all the nodes in the same level are traversed
                            // edge case: 
                            // hit -- hot
                            //   \      \
                            //.  git -- got
                            prevs[cur].insert(prev);
                        }
                    }
                    cur[j] = c; // easy to be forgot !!!
                }
            }
            for (auto& s : new_visited) { // don't forget to add all neighbors into visited
                visited.insert(s);
            }
            if (found_target) break;
            cur_len++;
        }
        
        vector<vector<string>> res;
        vector<string> path;
        dfs(beginWord, endWord, prevs, path, res);
        return res;
    }
};