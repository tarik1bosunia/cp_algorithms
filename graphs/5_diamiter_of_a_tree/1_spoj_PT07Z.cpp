#include<bits/stdc++.h>

using namespace std;

vector<int> ar[100001];
bool vis[100001];

int max_length = 0;
int one_end_vertex = 1;

void dfs1(int s = 1, int dist = 0){
    vis[s] = true;
    if(dist > max_length){
        max_length = dist;
        one_end_vertex = s;
    }
    for(int child : ar[s]){
        if(!vis[child]){

            dfs1(child, dist + 1);
        }
    }
}

void dfs2(int s, int dist = 0){
    vis[s] = true;
    if(dist> max_length){
        max_length = dist;
    }
    for(int child : ar[s]){
        if(!vis[child]){

            dfs2(child, dist + 1);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n, a, b;
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    
    dfs1();
    for(int i = 1; i<= n; i++){
        vis[i] = false;
    }
    max_length = 0;
    dfs2(one_end_vertex);

    cout << max_length << endl;
    
    return 0;
}
