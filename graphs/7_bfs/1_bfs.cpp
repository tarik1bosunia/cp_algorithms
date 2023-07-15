#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj; //adjacency list representation
int n; // number of nodes 
int s; // source vertex



void bfs(){
    queue<int> q;
    vector<bool> used(n);
    vector<int> p(n), d(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(!used[u]){
                used[u] = true;
                q.push(true);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    
    
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    
    return 0;
}

