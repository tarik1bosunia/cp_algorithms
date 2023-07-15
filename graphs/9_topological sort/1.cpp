#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // number of vertices edges
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;
vector<int> in;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort_kahns() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    // Define the graph
    int a, b;
    cin >> n >> m;
    adj.resize(n);
    in.assign(n, 0);
    for (int i = 0; i < m; i++) {
       cin >> a >> b;
       adj[a-1].push_back(b-1);
       in[b-1]++;
    }

    // Perform topological sort
    topological_sort_kahns();

    // Print the sorted vertices
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}