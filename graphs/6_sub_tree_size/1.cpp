#include<bits/stdc++.h>

using namespace std;

vector<int> ar[100001];
bool vis[100001];
int sub_size[100001];

int dfs(int s){
    int curr_size = 1;
    vis[s] = true;

    for(int child : ar[s]){
        if(!vis[child]){
            curr_size += dfs(child);
        }
    }

    sub_size[s] = curr_size;
    
    return curr_size;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, a, b;
    cin >> n;

    for(int i = 1 ; i <= n-1; i++){
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << sub_size[i] << " ";
    }
    
    
    
    return 0;
}
