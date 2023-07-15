#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ar;
vector<bool> onstack;
vector<bool> vis;
vector<int> in, low;
stack<int> stk;

int timer = 1, SCC = 0;

void dfs(int src){
    vis[src] = 0;
    in[src] = low[src] = timer++;
    onstack[src] = true;
    stk.push(src);

    for(int child : ar[src]){
        if(vis[child] && onstack[child]){
            low[src] = min(low[src],  in[child]);
        }else if(!vis[child]){
            dfs(child);

            if(onstack[child]){
                low[src] = min(low[src], low[child]);
            }
        }
    }
    if(in[src] == low[src]){
        SCC++;
        cout << "SCC #" << SCC << endl;

        int child;

        while (1)
        {
            child = stk.top();
            stk.pop(), onstack[child] = false;
            cout << child << " ";
            if(child == src) break;
        }
        cout << endl;
        

    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, m, a, b;
    cin >> n >> m;

    ar.assign(n+1, vector<int>());
    onstack.assign(n+1, false);
    vis.assign(n+1, false);
    in.assign(n+1, 0);
    low.assign(n+1, 0);

    for(int i = 1; i <= n; i++)
    if(!vis[i])
    dfs(i);


    while (m--)
    {
        cin >> a >> b, ar[a].push_back(b);
    }
    
    
    
    
    return 0;
}
