#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ar;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int s, int p = -1){
    visited[s] = true;
    tin[s] = low[s] = timer++;

    for(int to : ar[s]){
        if(to == p) continue;

        if(visited[to]){
            low[s] = min(low[s], tin[to] );
        }else{
            dfs(to, s);
            low[s] = min(low[s], low[to]);
            
            if(low[to] > tin[s]){
                cout << "there is a bridge from " << s << " to " << to << endl;
            }
        }


    }
}

void find_bridge(){
    int n , m, a , b;
    cin >> n >> m;

    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, 0);
    low.assign(n+1, 0);
    ar.assign(n+1, vector<int>());

    while (m--) cin >> a >> b, ar[a].push_back(b), ar[b].push_back(a);

    for (int i = 1; i < n; i++)
        if(!visited[i]) dfs(i);
        
    


    // print the graph
    // for (int i = 1; i <= n; i++) {
    //     cout << "Vertex " << i << ": ";
    //     for (int x : ar[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    find_bridge();
    
    return 0;
}
