package canonical;

public class UnionFind {
    private int[] parent; // parent[i] = parent of i
    private int[] size; // size[i] = number of element in tree rooted at i

    private int count; // number of isolated components

    public UnionFind(int n) {
        count = n;
        parent = new int[n];
        size = new int[n];
        for (int i=0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // do weighted union
    public void union(int a, int b) {
        int ra = findRoot(a);
        int rb = findRoot(b);
        if (ra == rb) return;
        if (size[a] > size[b]) {
            parent[rb] = ra;
            size[ra] += size[rb];
        } else {
            parent[ra] = rb;
            size[rb] += size[ra];
        }
        count--;
    }

    // find root via 2-hop and do compression afterwards
    public int findRoot(int a) {
        // first find root with 2 hops a time
        int cur = a;
        while (parent[cur] != cur) {
            cur = parent[parent[cur]]; // 2-hop, O(log*N)
        }
        int root = cur;

        // do compression by basically updating parents of all nodes as root
        while (a != root) {
            int tmp = parent[a]; // save next hop first before updating parent
            parent[a] = root;
            a = tmp;
        }

        return root;
    }

    public boolean connected(int a, int b) {
        return findRoot(a) == findRoot(b);
    }

    public int count() {
        return count;
    }
}
