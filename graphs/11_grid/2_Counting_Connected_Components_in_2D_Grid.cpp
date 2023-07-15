#include<bits/stdc++.h>

using namespace std;

int N , M;
bool vis[1001][1001];
int ar[1001][10001];

bool isValid(int x, int y){
    if(x <1 || x > N || y < 1 || y > M) return false;

    if(vis[x][y] == false || ar[x][y]= 0) return false;

    return true;
}


int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x , int y){
    vis[x][y] = true;

    cout << x << " " << y << endl;

    for(int i = 0; i < 4; i++){
        if(isValid(x+dx[i], y+dy[i])){
            dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    
    cin >> N >> M;
    for(int i =1; i<=N;i++)
    for(int j =1; j<=M;j++)
    cin >> ar[i][j];

    int cc = 0;

    for(int i =1; i<=N;i++)
    for(int j =1; j<=M;j++)
    if(vis[i][j] = 0 && ar[i][j] == 1)
    dfs(i, j), cc++;

    cout << cc << endl;

    return 0;
}
