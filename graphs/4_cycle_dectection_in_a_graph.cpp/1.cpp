#include<bits/stdc++.h>

using namespace std;

bool vis[10000];
bool color[10000];
vector<int>ar[10000];

bool dfs(int s, int par = -1){
   vis[s] = true;

   for(int child : ar[s]){
        if(!vis[child]){
            if (dfs(child, s)) return true;
        }
        else if(child == par){
            return true;
        }
         
        return false; 
   }

   return true;
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    


    return 0;
}
