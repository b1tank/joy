// Author: b1tank
// Email: b1tank@outlook.com
//=================================

// cpp essentials playground

#include <iostream>

#include <sstream> // stringstream, istringstream, ostringstream
#include <string> // to_string(), stoi()

#include <cctype> // isalnum, isalpha, isdigit, islower, isupper, isspace; toupper, tolower
#include <climits> // INT_MAX 2147483647
#include <cmath> // pow(3.0, 4.0); abs(-3.0)
#include <cstdlib> // rand() % 100 + 1; abs(-3)

#include <vector>
#include <forward_list> // singly-linked list
#include <list> // doubly-linked list
#include <stack>
#include <queue>
#include <deque>

#include <unordered_set> // unordered_set, unordered_multiset
#include <set> // set, multiset
#include <bitset> // bitset
#include <unordered_map> // unordered_map, unordered_multimap
#include <map> // map, multimap

#include <utility> // pair<>
#include <tuple> // tuple<>

#include <algorithm> // reverse, sort, transform, find, remove, count, count_if

#include <memory> // shared_ptr<>, make_shared<>

#include <stdexcept> // invalid_argument

using namespace std;

int main() {

    // cpp style ref: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es23-prefer-the--initializer-syntax

    // char and string
    char c = 'c';
    isalnum('2'); // #include<cctype>
    isalpha('a');
    isdigit('4');
    islower('z');
    isupper('Z');
    isspace(' ');
    char C = toupper(c);
    int d = 'c' - 'a';
    char e = 'c' + 2; 
    
    string a("str");
    string b("str2");

    long i = 28;
    to_string(i); // "28"
    stoi("28"); // 28
    string str_dec = "2001, A Space Odyssey";
    string str_hex = "40c3";
    string str_bin = "-10010110001";
    string str_auto = "0x7f";
    int i_dec = stoi (str_dec, &sz);
    int i_hex = stoi (str_hex, nullptr, 16);
    int i_bin = stoi (str_bin, nullptr, 2);
    int i_auto = stoi (str_auto, nullptr, 0);

    auto c = a.at(2);
    a.front() = 'B';
    a.back() = 'E';

    a.substr(4, 2); // 2 is len
    auto pos = a.find("tr");
    a.substr(pos); // from pos to the end
    string token = s.substr(0, s.find(delimiter)); // split string

    a += "suffix";
    a.append(b);
    a.append(b, 3, 2);
    a.append("string", 3);
    a.append("string");
    a.append(10u, '.');
    a.append(b.begin()+5, b.end());

    a.insert(2, "string", 3); // just add a "size_t pos" upon append method
    a.erase(10,9); // only apply to string (not to vector!!!)
    a.erase(a.begin()+7);
    a.erase(a.begin()+7, a.end());
    a.replace(10, 8, b, 7, 6); // just add a "size_t pos" and "size_t len" upon append method

    a.swap(b);

    a.push_back('c');
    a.pop_back();

    auto it = a.begin();
    auto it = a.end();
    auto it = a.rbegin();
    auto it = a.rend();
    if (a.empty()) {}

    int s = a.length();
    int ss = a.size();

    a.find("tr") == string::npos; // find or not
    a.find("tr");
    a.find("tr", 4);
    a.find("tr", 4, 1); // starting pos, len
    a.rfind("tr"); // last appearance
    a.rfind("tr", 4);
    a.rfind("tr", 4, 1);

    a.compare(6, 5, "apple", 4, 5); // <0, ==0, >0

    // number, power and random
    int ma = INT_MAX; // #include <climits> -2147483648, 2147483647
    int mi = INT_MIN;
    int p = pow(3.0, 4.0); // #include <cmath> 81
    int a = abs(-3); // #include <cstdlib> integral
    int a = abs(-3.0); // #include <cmath> double/float
    int r = rand() % 100; // #include <cstdlib> 0-99
    int r = rand() % 100 + 1; // #include <cstdlib> 1-100

    // bool and condition
    bool t = true;
    bool f = false;

    // loop
    for (auto c : a) {}
    for (auto it = a.begin(); it != a.end(); it++) {}
    for (auto it = a.rbegin(); it != a.rend(); it++) {}

    // vector
    vector<int> v{2, 3, 4};
    vector<int> v(3);
    vector<int> v(3, 8);
    vector<vector<int>> v(3, vector<int>(8));
    vector<int> v(v1.begin()+1, v1.end());
    vector<pair<int, int>> vp;

    v = v1; // copy another vector
    v = vector<int>(); // const vector<>&
    v = {2, 3}; // initializer list

    // return {}; // return empty vector
    // return vector<int>();

    v.push_back(4);
    v.pop_back();
    vp.emplace_back(3, 5); // implicit constructor 
    auto it = v.insert(v.end(), v2.begin(), v2.end());
    auto it = v.insert(v.begin()+2, 7);
    auto it = v.insert(v.begin(), 2, 7); // insert 2 "7"s
    auto it = v.erase(v.begin()+1);
    auto it = v.erase(v.begin()+1, v.end());
    v.swap(v2);
    v.clear();

    int vf = v.front();
    int vf = v.back();
    auto it = v.begin();
    auto it = v.end();
    auto it = v.rbegin();
    auto it = v.rend();

    if (v.empty()) {}

    // stack (by default underlying container is <deque>)
    // * Queue, Stack, and Priority_queue has no begin()/end(). Can't do loop. Can't modify elements by clear(), reverse().
    stack<int> st;
    stack<int> st1;
    stack<pair<int, int>> st2;

    int s = st.size();
    if (st.empty()) {}

    st.push(3); // st.push_back() of underlying container
    st2.emplace(2, 3);
    st.pop(); // st.pop_back() of underlying container

    st.top(); // st.back() of underlying container

    st.swap(st1); // cannot swap with st2 !!!

    // queue (by default underlying container is <deque>)
    queue<int> q;
    queue<int> q1;
    queue<pair<int, int>> q2;

    int s = q.size();
    if (q.empty()) {}

    q.push(3);
    q2.emplace(2, 3);

    q.front();
    q.back();

    q.pop(); // pop_front() of underlying container

    q.swap(q1); // cannot swap with q2 !!!

    // deque 
    deque<int> dq;
    deque<int> dq1;
    deque<pair<int, int>> q2;

    int s = dq.size();
    if (dq.empty()) {}

    dq.push_front(3);
    dq.push_back(3);
    dq1.emplace(dq.begin()+2, 8, 3); // pos (1st arg)
    dq1.emplace_front(8, 3);
    dq1.emplace_back(8, 3);

    dq.front();
    dq.back();

    dq.begin();
    dq.end();
    dq.rbegin();
    dq.rend();

    dq.pop_front();
    dq.pop_back();

    dq.swap(q1); // cannot swap with q2 !!!

    // priority_queue (by default: Max-Heap; <vector> as the underlying container)
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq1; // Min-Heap
    priority_queue<pair<int, int>> pq2;

    int s = pq.size();
    if (pq.empty()) {}

    pq.push(3);
    pq2.emplace(2, 3);

    int t = pq.top();

    pq.pop();

    pq.swap(pq1); // cannot swap with pq2

    class point{
    public:
        int x;
        int y;
        point(int x, int y):x(x),y(y) {}
    };

    class pointCompLessThan {
    public:
        bool operator()(point& a, point& b) {  // operator()!!!
            return a.x < b.x;
        }
    };

    priority_queue<point, vector<point>, pointCompLessThan> Q;
    Q.emplace(1, 2);

    // bitset (index 0 from the right end !!!!!)
    vector<bitset<26>> dp;
    bitset<26> set_i(0);
    bitset<26> set_j(string("10101001"));
    set_i[1] = 1;
    int n = set_i.size(); // 26
    if (set_i.count() == 1) {}
    if ((set_i & set_j).none()) {}
    if ((set_i | set_j).any()) {}
    if ((set_i ^ set_j).all()) {}
    set_i.set(c - 'a');
    set_i.set(); // apply to all bits
    set_i.reset(c - 'a');
    set_i.reset();
    set_i.flip(c - 'a');
    set_i.flip();

    // unordered set and multiset; map and multimap
    // * Can be looped through using iterators from begin() to end()
    // * Array/vector are not hashable. One way to work around is to convert it to strings.
    unordered_set<int> s;
    unordered_set<int> s1{"red", "blue", "green"}; // {} is list initialization for containers, which is preferred !!!
    // unordered_set<int> s1( {"red", "blue", "green"} ); // also correct but allows parsing ambiguities !!!
    unordered_map<string, int> m;
    unordered_map<string, int> m1{{"red", 1}, {"blue", 2}, {"green", 3}}; // {} is list initialization for containers, which is preferred !!!
    // unordered_map<string, int> m1( {{"red", 1}, {"blue", 2}, {"green", 3}} ); // also correct but allows parsing ambiguities !!!

    int ss = s.size();
    if (s.empty()) {}

    auto it = s.begin();
    auto it = s.end();

    if (s.find(5) != s.end() || s.count(5) == 1) {}

    s.insert("orange");
    s.insert(v.begin(), v.end());
    s.insert( {"orange", "purple"} ); // initializer list
    s.erase("blue");
    s.erase(s.begin()+2);
    s.erase(s.begin()+2, s.end());

    pair<string, int> mypair ("baking powder", 3);
    m.insert (mypair);                        // copy insertion
    m.insert (make_pair<string, int>("eggs", 6)); // move insertion
    m.insert (m1.begin(), m2.end());  // range insertion
    m.insert ( {{"sugar", 8}, {"salt", 1}} );    // initializer list insertion

    s.swap(s2);

    unordered_multiset<int> ms( { 2, 3, 2, 4, 2} );
    int count = ms.count(2); // 3
    auto myrange = ms.equal_range(2);
    while (myrange.first != myrange.second) {
        cout << *myrange.first++ << endl;
    }

    // (ordered) set and multiset; (map and multimap)
    set<int> s;
    set<int> s1{"red", "blue", "green"}; // {} is list initialization for containers, which is preferred !!!
    // set<int> s1( {"red", "blue", "green"} ); // also correct but allows parsing ambiguities !!!

    int ss = s.size();
    if (s.empty()) {}

    auto it = s.begin();
    auto it = s.end();
    auto it = s.rbegin();
    auto it = s.rend();

    if (s.find(5) != s.end() || s.count(5) == 1) {}

    s.insert("orange");
    s.insert(v.begin(), v.end());
    s.insert( {"orange", "purple"} ); // initializer list
    s.erase("blue");
    s.erase(s.begin()+2);
    s.erase(s.begin()+2, s.end());

    s.swap(s2);

    unordered_multiset<int> ms( { 2, 3, 2, 4, 2} );
    int count = ms.count(2);
    auto it = ms.lower_bound(3);
    auto it = ms.upper_bound(4);
    auto myrange = ms.equal_range(2);
    while (myrange.first != myrange.second) {
        cout << *myrange.first++ << endl;
    }

    // pair (<utility>) and tuple (<tuple>)
    pair <string, double> p1 ("tomatoes", 2.30);
    p1.first;
    p1.second;

    tuple<int,char> foo (10, 'x');
    auto bar = make_tuple ("test", 3.1, 14, 'y');

    get<2>(bar) = 100;                          // access element

    int myint; char mychar;
    tie (myint, mychar) = foo;                  // unpack elements
    tie (ignore, ignore, myint, mychar) = bar;  // unpack (with ignore)

    //// data structure
    // tree
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode (int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // trie
    class TrieNode {
    public:
        // vector<TrieNode*> next;
        bool isEnd;
        vector<shared_ptr<TrieNode>> next;
        
        TrieNode() : isEnd(false), next(26, nullptr) {}
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
    };

    // single-linked list
    struct ListNode {
        int val;
        ListNode* next;
        ListNode (int v) : val(v), next(nullptr) {};
    };

    // double-linked list
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode (int v) : val(v), prev(nullptr), next(nullptr) {};
    };

    // graph node and graph (adjacency list)
    struct GraphNode {

        int val;
        // string str;
        vector<GraphNode*> neighbors;
        // vector<int> neighbors;
        // vector<string> neighbors;
        // vector<pair<string, int>> neighbors; // weighted edges
        // unordered_set<int> neighbors;
        // unordered_set<string> neighbors;
        // unordered_set<pair<string, int>> neighbors; // weighted edges

        GraphNode() {
            val = 0;
            neighbors = vector<GraphNode*>();
        }

        GraphNode(int _v) {
            val = _v;
            neighbors = vector<GraphNode*>();
        }

        GraphNode(int _v, vector<GraphNode*> _ns) {
            val = _v;
            neighbors = _ns;
        }
    };

    // ref: https://www.redblobgames.com/pathfinding/a-star/implementation.cpp
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
    }; // {} gives direct initialization with explicit constructor; whereas ={} gives copy initialization !!!!!
    
    //// algorithm

    // STL
    transform(a.begin(), a.end(), a.begin(), toupper); // #include<algorithm>
    auto it = find(a.begin(), a.end(), "str"); // #include<algorithm>
    reverse(v.begin(), v.end()); // #include<algorithm>
    sort(v.begin(), v.end()); // #include<algorithm>
    sort(v.begin(), v.end(), boolFuncLessThan); // #include<algorithm> asc
    sort(v.begin(), v.end(), [](point& a, point& b) {return a.y < b.y;});
    sort(v.begin(), v.end(), boolFuncGreaterThan); // #include<algorithm> desc
    auto it = remove(v.begin(), v.end(), 13); // #include<algorithm>
    int count = count(v.begin(), v.end(), 13); // #include<algorithm>
    int count_if = count_if(v.begin(), v.end(), boolFunc); // #include<algorithm>

    // split string
    // ref: https://doc.bccnsoft.com/docs/cppreference_en/cppsstream/all.html

    // #include <boost/algorithm/string.hpp>
    // string s = "hello world";
    // vector<string> res;
    // boost::split(res, s, [](char c){return c == ' ';});

    istringstream iss(s); // or stringstream
    // or ss << s;
    // or ss.str(s);
    vector<string> res;
    string token;
    char delimiter = ' ';
    while(getline(ss, token, delimiter)) {
        res.push_back(token);
    }

    // join strings
    ostringstream oss;
    if (begin != end) ss << *begin++;
    while (begin != end) {
        ss << delimiter;
        ss << *begin++;
    }
    ss << concluder;
    string joined_str = ss.str();

    // stringstream peek and EOF (empty stringstream is a special case!!!)
    stringstream ss("");
    ss.peek(); // make empty ss reach EOF !!!
    if (ss.eof()) {} // true; false without peek() call above

    // binary search
    int target = 4;
    vector<int> arr{1, 2, 3, 4, 5};
    int l = 0;
    int r = arr.size()-1;
    while (l < r) { // or l <= r
        int mid = l + (r-l) / 2;
        if (target == arr[mid]) {
            return mid;
        } else if (target > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid; // or r = mid - 1
        }
    }

    // Depth first seach (DFS)
    void dfs_iterative (vector<vector<int>> graph, int start) {
        stack<int> st{start};
        unordered_set<int> visited{start};
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            for (auto& n : graph[cur]) {
                if (visited.find(n) == visited.end()) {
                    visited.insert(n);
                    st.push(n);
                }
            }
        }
    }
    void dfs_recursive (vector<vector<int>> graph, int start, unordered_set<int> visited) {
        visited.insert(start);
        for (auto& n : graph[cur]) {
            if (visited.find(n) == visited.end()) {
                dfs_recursive(graph, n, visited);
            }
        }
    }

    // Breadth first seach (BFS)
    void bfs (vector<vector<int>> graph, int start, int target) {
        queue<pair<int, int>> q; // depth (cost), node_val
        q.emplace(0, start);  
        unordered_set<int> visited{start};
        while (!q.empty()) {
            int cur_depth = q.front().first;
            int cur = q.front().second;
            q.pop();
            if (cur == target) return cur_depth; // shortest path to target
            for (auto& n : graph[cur]) {
                if (visited.find(n) == visited.end()) {
                    visited.insert(n);
                    q.emplace(cur_depth + 1, n);
                }
            }
        }
    }

    // Dijkstra's algorithm
    void dijksta (vector<vector<pair<int, int>>> graph, int start, int target) {
        // Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, node
        pq.emplace(0, start);
        while (!pq.empty()) {
            int cur_cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (cur == target) return cur_cost; // shortest path to target
            for (auto& n : graph[cur]) {
                int n_weight = n.first;
                int n_node = n.second;
                pq.emplace(cur_cost + n_weight, n_node);
            }
        }
    }

    // A* algorithm
    inline int heuristic (int& a, int& b) {
        return abs(a - b);
    }
    void a_star (vector<vector<pair<int, int>>> graph, int start, int target) {
        // Min-Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, node
        pq.emplace(0, start);
        
        unordered_map<int, int> prev; // node, node (prev)
        unordered_map<int, int> cost; // node, cost

        while (!pq.empty()) {
            int cur_cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (cur == target) return cur_cost; // shortest path to target
            for (auto& n : graph[cur]) {
                int n_weight = n.first;
                int n_node = n.second;
                int new_cost = cur_cost + n_weight;
                if (cost.find(n_node) == cost.end() || new_cost < cost[n_node]) {
                    cost[n_node] = new_cost;
                    pq.emplace(new_cost + heuristics(n_node, target), n_node);
                    prev[n_node] = cur;
                }
            }
        }
    }

    // Topological sort (In-degree; Adjacency matrix - Adjacency list)
    int n = 10;
    vector<pair<int, int>> prerequisites;
    vector<vector<int>> graph(n); // adjacency list
    vector<int> in_degree(n, 0);
    vector<int> res;

    // construct graph from edges (adjacency matrix) and compute in-degrees
    for (auto &p: prerequisites) {
        graph[p.second].push_back(p.first);
        in_degree[p.first]++; 
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i); 
            res.push_back(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); 
        q.pop();
        for (auto& n: graph[cur]) {
            in_degree[n]--;
            if (in_degree[n] == 0) {
                q.push(n); 
                res.push_back(n);
            }
        }
    }

    // union-find
    // - canonical implementation of Weighted Union-Find with path compression
    //     - weighted: size of each component
    //     - path compression: update nodes' direct parent as root
    // - Complexity
    //     - UnionFind(): O(N)
    //     - find_root(): nearly 1 (amortized)
    //     - union_weighted(): nearly 1 (amortized)
    //     - connected(): nearly 1 (amortized)
    //     - count(): O(1)
    // - ref
    //     - https://algs4.cs.princeton.edu/15uf/WeightedQuickUnionPathCompressionUF.java.html
    //     - https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
    class UnionFind {
        int count;
        vector<int> parent;
        vector<int> size;
    public:
        UnionFind(int N) : count(N), parent(N), size(N, 1) {
            for (int i=0; i < N; i++) {
                parent[i] = i;
            }
        }
        void union(int p, int q) {
            int rp = find_root(p);
            int rq = find_root(q);
            if (rp == rq) return;

            if (size[p] < size[q]) {
                parent[p] = rq;
                size[q] += size[p];
            } else {
                parent[q] = rp;
                size[p] += size[q];
            }
            count--;
        }

        int find_root(int p) {
            int root = p;
            while(parent[p] != p) {
                p = parent[parent[p]]; // log(N)
            }
            // update all parents with root value
            while(p != root) {
                int tmp = parent[p];
                parent[p] = root;
                p = tmp;
            }
            return root;
        }

        bool connected(int p, int q) {
            return find_root(p) == find_root(q);
        }

        int count() {
            return count;
        }
    };


    // copy and move (lvalue, rvalue)
    // ref: https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
    // lvalue: provides a (semi)permanent piece of memory
    // rvalue: a temporary object
    // copy (without std::move()) is more time-expensive
    std::move(lvalue); // return rvalue

    // smart pointers
    shared_ptr<int> sp; // increment counter when sp1 = sp
    unique_ptr<int> up; // always do std::move() when up1 = up

    // inline function
    // compiler will insert the body of the function in that location as opposed to making a function call
    // only for small functions that are used frequently, not for large functions
    inline void swap(int & a, int & b) // inline is a compiler directive
    {
        // code needs to be recompiled when the function is changed
        int temp = a;
        a = b;
        b = temp;
    }

    // lambda function
    // ref: https://lospi.net/c++/developing/software/visual%20studio/2015/03/11/lambdas-and-cpp11.html
    std::transform(
        words.begin(), words.end(), 
        result.begin(),
        [&](int x){ return x + a - b; } // all passed by reference
        //[=](int x){ return x + a - b; } // all passed by value
        //[a, &b](int x){ return x + a - b; } // a passed by value, b passed by reference
    );

    // exception handling
    // * Common exceptions: http://stdcxx.apache.org/doc/stdlibref/2-3.html
    try {
        bitset<5> bs(string("01234")); // "234" are invalid
        // throw invalid_argument( "Invalid argument!" );
    } catch( const invalid_argument& e ) {
        cerr << "Invalid Argument: " << e.what() << endl;
    }
}