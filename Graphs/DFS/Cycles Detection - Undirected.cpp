#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
//using ll = long long;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool dfsCycles(vector<vector<int>> adj, int src, vector<bool>& vis, int parent) {
    vis[src] = true;
    for (int i : adj[src]) {
        if (!vis[i]) {
            if (dfsCycles(adj, i, vis, src))  {
                return true;
            }
        }
        else {
            if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>> adj, int n) {
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsCycles(adj, i, vis, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    IO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << isCyclic(adj, n);
    return 0;
}
/*
Your Question was why not to use this code for Cycle detection for Directed graph
The Answer is this just try this test for directed graph : 
3 3
1 2
1 3
3 2

Without the recursion stack, the algorithm cannot distinguish between:
    1. A node that has been visited in a previous DFS traversal (no cycle).
    2. A node that is part of the current DFS path (cycle).
*/
--------------------------------------------------------------------------------------------------------
// Check What is going here :
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<bool> cyc;

bool dfsRec (vector<bool> &vis, vector<int> adj[], int cur, int parent) {
    vis[cur] = cyc[cur] = true;
    for (auto &i : adj[cur]) {
        if (cyc[i]) {
            // there is a cycle
            // in both directed and undirected graphs
            return true;

        }
        if (!vis[i]) {
            if (dfsRec(vis, adj, i, cur)) {
                return true;
            }
        }
        // else : it is already visited
        // Therefore if we enter here, there is a cycle
        else { // already visited
            // have to checck that it is not the parent of the current node
            // as for undirected graph we take the edge from two different perpectives
            // 2 - 1 == 1 - 2 so this doesn't indicate a cycle
            if (i != parent) {
                return true;
            }
        }
    }
    cyc[cur] = false; // zyha zy in stack ??
    return false;
}

bool isCyclic (vector<int> adj[], int n) {
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfsRec(vis, adj, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

/*
bool isCyclicUtil(int v, vector<vector<int>>& adj,
                  bool visited[], int parent) {
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    for (int i : adj[v]) {
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[i]) {
            if (isCyclicUtil(i, adj, visited, v))
                return true;
        }
            // If an adjacent vertex is visited and
            // is not parent of current vertex,
            // then there exists a cycle in the graph.
        else if (i != parent)
            return true;
    }
    return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool isCyclic(int V, vector<vector<int>>& adj) {
    // Mark all the vertices as not visited
    bool* visited = new bool[V]{false};

    // Call the recursive helper function
    // to detect cycle in different DFS trees
    for (int u = 0; u < V; u++) {
        // Don't recur for u if it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, adj, visited, -1))
                return true;
    }
    return false;
}*/
int main() {
    IO;
    int n, edges;
    cin >> n >> edges;
    int u, v;
    vector<int> adj[n];
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << isCyclic(adj, n);
    return 0;
}
