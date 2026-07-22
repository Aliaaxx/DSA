class UnioFind{
private :
    vector<int> root;
    vector<int> rank;

public:
    UnioFind(int sz) : root(sz), rank(sz){
        for (int i = 0; i < sz; i++) {
            root[i] = i; // every node is a union root
            rank[i] = 1;
        }
    }

    int Find(int x) {
        if (x == root[x]){
            return x;
        }
        return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
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

    bool isConnected(int x, int y) {
        return Find(x) == Find(y);
    }
};
