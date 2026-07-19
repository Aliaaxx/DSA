/*
 * Data Structure: Disjoint Set (Union-Find)
 * Implementation: Quick Union
 *
 * Idea:
 * Each element points to its parent.
 * The root of a tree is the representative of the connected component.
 *
 * Time Complexity:
 *   Find()         : O(n) in the worst case
 *   Union()        : O(n) (because it calls Find twice)
 *   isConnected()  : O(n)
 *
 * Space Complexity:
 *   O(n)
 */

class UnionFind {
private:
    // root[i] stores the parent of node i.
    // If root[i] == i, then i is the root (representative) of its set.
    vector<int> root;

public:
    // Initially, every node is its own parent,
    // meaning each node starts in its own connected component.
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    // Find the representative (root) of the set containing x.
    // Keep moving up the parent pointers until a node is its own parent.
    int Find(int x) {
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }

    // Merge the sets containing x and y.
    // Connect the root of y's tree to the root of x's tree.
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX != rootY) {
            root[rootY] = rootX; // rootY not y
        }
    }

    // Two nodes are connected if they have the same root.
    bool isConnected(int x, int y) {
        return Find(x) == Find(y);
    }
};
