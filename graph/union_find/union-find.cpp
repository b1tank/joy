// Author: b1tank
// Email: b1tank@outlook.com
//=================================

/*
union-find.cpp 

Solution: 
    - canonical implementation of Weighted Union-Find with path compression
        - weighted: size of each component
        - path compression: update nodes' direct parent as root
    - Complexity
        - UnionFind(): O(N)
        - find_root(): nearly 1 (amortized)
        - union_weighted(): nearly 1 (amortized)
        - connected(): nearly 1 (amortized)
        - count(): O(1)
    - ref
        - https://algs4.cs.princeton.edu/15uf/WeightedQuickUnionPathCompressionUF.java.html
        - https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/

*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class UnionFind {

    int count;
    vector<int> hm_parent;
    vector<int> hm_size;

public:
    // init
    UnionFind(int N) : count(N), hm_parent(N), hm_size(N, 1) {
        for (int i = 0; i < N; i++) {
            hm_parent[i] = i;
        }
    }

    // root
    int find_root(int i) {
        int root = i;
        while (hm_parent[root] != root) {
            root = hm_parent[hm_parent[root]]; // grandparent, log(*N)
        }
        // update all nodes' direct parent as root (path compression)
        while (i != root) {
            int next_i = hm_parent[i];
            hm_parent[i] = root;
            i = next_i;
        }
        return root;
    }

    // union
    void union_weighted(int a, int b) {
        int ra = find_root(a);
        int rb = find_root(b);
        if (ra = rb) return;
        if (hm_size[ra] < hm_size[rb]) {
            hm_parent[ra] = rb;
            hm_size[rb] += hm_size[ra];
        } else {
            hm_parent[rb] = ra;
            hm_size[ra] += hm_size[rb];
        }
        count--;
    }

    bool connected(int a, int b) {
        return find_root(a) == find_root(b);
    }

    int count() {
        return count;
    }
};