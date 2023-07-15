#include<bits/stdc++.h>

using namespace std;

bool vis[10000];
bool color[10000];
vector<int>ar[10000];

bool dfs(int s, bool c){
   vis[s] = true;
   color[s] =  c;

   for(int child : ar[s]){
        if(!vis[child]){
            if (dfs(child, c ^ 1) == false) return false;
        }
        else if(color[s] == color[child]) return false;    
   }

   return true;
}


void solve(int t){
    int m, n, a, b;
    bool flag = true;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
         vis[i] = false;
         color[i] = false;
         ar[i].clear();   
    }

    while (m--)
    {
        cin >> a >> b;
        ar[a].push_back(b), ar[b].push_back(a);
    }
    for(int i = 1; i <=n; i++){
       if(!vis[i]){
         if(!dfs(i, false)){
            flag = false;
            break;
        }
       }
    }
    cout << "Scenario #" << t << ":" << endl;
    if(flag){
        cout << "No suspicious bugs found!" << endl;
    }else{
        cout << "Suspicious bugs found!" << endl;
    }
    
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int t;
    cin >> t;
    for(int i = 1; i <=t; i++) solve(i);

    return 0;
}
