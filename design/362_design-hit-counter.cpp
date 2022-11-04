// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
362_design-hit-counter LeetCode

Solution: 
    - buckets using mod (rolling window)
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

class HitCounter {
    vector<int> times;
    vector<int> hits;
    // queue<pair<int, int>> q;
    // int capacity;
    // int sum;
public:
    // hit(3);
    // getHits(4); // 1
    // hit(5);
    // hit(5);
    // hit(5);
    // getHits(6); // 4
    // getHits(303) // 4
    // getHits(304) // 3
    // getHits(306) // 0
    
    // 00101
    // 00001
    // 00001
    
    
    /** Initialize your data structure here. */
    HitCounter() : times(300, 0), hits(300, 0) {
        // capacity = 300;
        // sum = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index]++;
        }
        // while (!q.empty() && timestamp - q.front().first >= capacity) {
        //     sum -= q.front().second;
        //     q.pop();
        // }
        // if (!q.empty() && timestamp == q.back().first) { // multiple hits at the same time
        //     q.back().second++;
        // } else {
        //     q.emplace(timestamp, 1);
        // }
        // sum++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int sum = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) {
                sum += hits[i];
            }
        }
        return sum;
        // while (!q.empty() && timestamp - q.front().first >= capacity) {
        //     sum -= q.front().second;
        //     q.pop();
        // }
        // return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */