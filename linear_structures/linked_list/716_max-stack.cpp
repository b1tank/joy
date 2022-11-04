// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
716_max-stack LeetCode

Solution: 
    - 
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

class MaxStack {
    list<int>List;
    map<int,vector<list<int>::iterator>>Map;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) 
    {
        List.push_back(x);
        Map[x].push_back(--List.end());
    }
    
    int pop() 
    {
        int x=List.back();
        List.pop_back();
        Map[x].pop_back();
        if (Map[x].size()==0)
            Map.erase(x);
        return x;
    }
    
    int top() 
    {
        return List.back();
    }
    
    int peekMax() 
    {
        return Map.rbegin()->first;
    }
    
    int popMax() 
    {
        int x = Map.rbegin()->first;
        List.erase(Map[x].back());
        Map[x].pop_back();
        if (Map[x].size()==0)
            Map.erase(x);
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */