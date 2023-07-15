#include<bits/stdc++.h>

using namespace std;

int N , M;
bool vis[1001][1001];

bool isValid(int x, int y){
    if(x <1 || x > N || y < 1 || y > M) return false;

    if(vis[x][y]) return false;

    return true;
}

void dfs1(int x , int y){
    vis[x][y] = true;

    cout << x << " " << y << endl;

    if(isValid(x-1, y)) dfs1(x-1, y); // up
    if(isValid(x+1, y)) dfs1(x+1, y);// down
    if(isValid(x, y-1)) dfs1(x, y-1);// left
    if(isValid(x, y+1)) dfs1(x, y+1); // right
}

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0, -1, 1};

void dfs2(int x , int y){
    vis[x][y] = true;

    cout << x << " " << y << endl;

    for(int i = 0; i < 4; i++){
        if(isValid(x+dx[i], y+dy[i])){
            dfs2(x+dx[i], y+dy[i]);
        }
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif
    
    cin >> N >> M;

    dfs2(1,1);
    
    
    
    return 0;
}
