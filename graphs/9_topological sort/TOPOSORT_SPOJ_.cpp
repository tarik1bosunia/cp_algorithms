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

vector<int> g[10001];
vector<int> ans;
int in[10001];

bool kans_topological_sort(int n){
  
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 1 ; i<=n ; i++) {
        if(in[i] == 0)
         pq.push(i);
    }

    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        ans.push_back(curr);

        for( int child : g[curr]){
            in[child]--;
            if(in[child] == 0) pq.push(child);
        }
    }
    
    
    return ans.size() == n;
}
    
int main(){
    // freopen("input.txt", "r", stdin);
   
    int n, m, x, y;
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;

    }
    // print out the adjacency list of the graph
    // for (int i = 1; i <= n; i++) {
    //     cout << "Vertex " << i << ": ";
    //     for (int x : g[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    //    // Print the sorted vertices
    //     for (auto v : ans) {
    //         cout << v << " ";
    //     }
    //     cout << endl;

    if(kans_topological_sort(n)){
        // Print the sorted vertices
        for (int v : ans) {
            cout << v << " ";
        }
        cout << endl;
    }else{
        cout << "Sandro fails" << endl;
    }
    
   
    
    return 0;
}

