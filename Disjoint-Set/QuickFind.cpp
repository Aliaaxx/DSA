/*
 * Data Structure: Disjoint Set (Union-Find)
 * Implementation: Quick Find
 *
 * Time Complexity:
 *   Find          : O(1)
 *   Union         : O(n)
 *   isConnected   : O(1)
 *
 * Space Complexity:
 *   O(n)
 */

class UnionFind {
private:
    // root[i] stores the set (component) id of element i.
    // In Quick Find, all elements in the same connected component have the same id.
    vector<int> root;

public:
    // Initially every element is in its own set.
    // So each element's id is itself.
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    // Returns the component id of x.
    // O(1)
    int Find(int x) {
        return root[x];
    }

    // Merge the components containing x and y.
    // We change every element that belongs to y's component
    // so it now belongs to x's component.
    // O(n)
    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        // Update every element that belongs to rootY.
        if (rootX != rootY) {
            for(int i = 0; i < root.size(); i++) {
                if (root[i] == rootY) {
                    root[i] = rootX;
                }
            }
        }
    }

    // Two elements are connected if they have the same component id.
    // O(1)
    bool isConnected(int x, int y) {
        return Find(x) == Find(y);
    }
};
