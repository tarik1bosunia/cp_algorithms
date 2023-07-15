#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

int n; // number of nodes 
vector<int> adj[1000001]; //adjacency list of graph
bool visited[1000001];
int tin[10000001], low[1000001];
int timer;

void IS_BRIDGE(int v, int to){
    cout << "there is a bridge " << v  << " - " << to << endl;
}

void dfs(int v, int p = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for(int to : adj[v]){
        if (to == p) continue;
        if(visited[to]){
            // p - to is a backedge  
            low[v] = min(low[v], tin[to]);

        }else{
            // forward edge
            dfs(to , v);
            low[v] = min (low[v], low[to]);
            if(low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}



void find_bridges(){
    int n, m, x , y;
    cin >> n >> m ;
    timer = 0;
    for(int i = 1; i <= n; i++){
        visited[i] = false;
        tin[i] = (-1);
        low[i] = (-1);
    }
    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
  
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
     // print out the adjacency list of the graph
    // for (int i = 1; i <= n; i++) {
    //     cout << "Vertex " << i << ": ";
    //     for (int x : adj[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
}
    
int main(){
    freopen("input.txt", "r", stdin);
    
    find_bridges();

    
    return 0;
}

