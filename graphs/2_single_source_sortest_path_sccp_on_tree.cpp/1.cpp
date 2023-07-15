#include<bits/stdc++.h>

using namespace std;

bool vis[1000001];
int dist[1000001];
vector<int> ar[1000001];

void dfs(int s, int d){
    vis[s] = true;
    dist[s] = d;

    for(int child : ar[s]){
        if(!vis[child]) dfs(child, d + 1);
    }
        
        
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    

    int a, b, n, m;

    cin >> n ;

    for(int i = 1; i <= n -1; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }

 

    
    return 0;
}
