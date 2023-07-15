#include<bits/stdc++.h>

using namespace std;

bool vis[1000001];
vector<int> ar[1000001];

void dfs(int s){
    vis[s] = true;

    for(int child : ar[s]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    

    int a, b, n, m;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }

    int connected_component = 0;

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i), connected_component++;
    }

    if(m == n-1 && connected_component == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    
    return 0;
}
