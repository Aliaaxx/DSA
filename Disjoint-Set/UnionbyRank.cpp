/*
 * Data Structure: Disjoint Set (Union-Find)
 * Optimization: Union by Rank
 *
 * Union by Rank is an optimization of the Quick Union implementation.
 *
 * Instead of connecting trees arbitrarily, it chooses the new root
 * based on the rank (approximate height) of each tree.
 *
 * The shorter tree is attached under the taller tree to keep the
 * resulting tree as balanced and as shallow as possible.
 *
 * If both trees have the same rank, either root can become the new
 * root, and its rank increases by one.
 *
 * By preventing trees from becoming long chains, Find and Union
 * operations improve from O(n) to O(log n) in the worst case.
 */

class UnionFind {
private:
    vector<int> root;
    vector<int> rank; // rank[i] represents an upper bound on the height of the tree whose root is i, it is meaningful only for root nodes.

public:
    explicit UnionFind(int size) : root(size), rank(size, 1) { // can be rank(size) only and the start to be 0
        for (int i = 0; i < size; ++i) {
            root[i] = i;
        }
    }

    // Union by rank guarantees that the tree height is O(log n).
    // Time complexity: O(log n) in the worst case.
    int find(int x) const {
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }

    /*
     * To keep the resulting tree short:
     * 1. Attach the shorter tree under the taller tree.
     * 2. If both trees have the same rank, either root may become the new root. The new root's rank then increases by one.
     */
    // Only roots are connected.
    // Time complexity: O(log n), caused by the two find operations.
    void unite(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            }
            else if (rank[rootY] > rank[rootX]) {
                root[rootX] = rootY;
            }
            else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    // Time complexity: O(log n).
    bool isConnected(int x, int y) const {
        return find(x) == find(y);
    }
};
