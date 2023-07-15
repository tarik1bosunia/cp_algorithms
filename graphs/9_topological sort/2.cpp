#include<bits/stdc++.h>

using namespace std;

int n, m; // number of vertices edges
vector<vector<int>> adj; // adjacency list of graph
vector<int> ans;
vector<int> in;


void topological_sort_kahns() {
    ans.clear();

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << in[i] << " ";
    // }
    // cout << endl;
    //  // Print the sorted vertices
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
 

    
    while (!q.empty())
    {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();

        for(int child : adj[curr]){
            in[child]--;
            if(in[child] == 0){
                q.push(child);
            }
        }
    }
    
    
}

int main() {
    freopen("input.txt", "r", stdin);
    // Define the graph
    int a, b;
    cin >> n >> m;
    adj.resize(n + 1);
    in.assign(n+1 , 0);
    for (int i = 1; i <= m; i++) {
       cin >> a >> b;
       adj[a].push_back(b);
       in[b]++;
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