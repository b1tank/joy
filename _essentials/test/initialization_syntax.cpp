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

int main()
{
    struct Graph {
        unordered_map<char, vector<char>> edges;
        // unordered_map<int, vector<int>> edges;
        // ... other types
        vector<char> neighbors (char val) {
            return edges[val];
        }
    };
    Graph g {
        {
            { 'A', {'B'} },
            { 'B', {'C', 'D'} },
            { 'C', {'A'} },
            { 'D', {'B'} }
        }
    };
    cout << g.edges['A'][0] << endl;
    cout << g.edges['B'][0] << endl;

    unordered_set<string> s1{"haha", "ere", "ewew"};
    unordered_set<string> s2({"haha", "ere", "ewew"});
    unordered_map<string, int> m1{{"haha", 2}, {"ere", 3}, {"ewew",4}};
    unordered_map<string, int> m2({{"haha", 2}, {"ere", 3}, {"ewew",4}});

    for (auto& s : s1) {
        cout << s << endl;
    }
    for (auto& s : s2) {
        cout << s << endl;
    }
    for (auto& s : m1) {
        cout << s.first << " " << s.second << endl;
    }
    for (auto& s : m2) {
        cout << s.first << " " << s.second << endl;
    }
    return 0;
}