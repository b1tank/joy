// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
1236_web-crawler LeetCode

Solution: 
    - s.substr(0, s.find('/', 7))
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
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> res;
        queue<string> q;
        q.push(startUrl);
        unordered_set<string> visited;
        string hostname = startUrl.substr(7, startUrl.find('/', 7) - 7); // nice use of find and substr to extract something
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            visited.insert(cur);
            res.push_back(cur);
            vector<string> ns = htmlParser.getUrls(cur);
            for (auto& n : ns) {
                if (n.find(hostname) != string::npos && visited.find(n) == visited.end()) { // find substr in a string
                    q.push(n);
                    visited.insert(n);
                }
            }
        }
        return res;
    }
};