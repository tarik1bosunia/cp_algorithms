#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int ar[100001];
int st[400004];

void buildTree(int si, int ss, int se){

    if(ss == se){
        st[si] = ar[ss];
        return;
    }

    int mid = (ss + se )/ 2;

    buildTree(2 * si, ss, mid);
    buildTree(2 * si + 1, mid + 1, se);

    st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe){
    if(ss > qe || se < qs ) // completely outside
    return INF;

    if(ss >= qs && se <= qe) // completly inside
    return st[si];

    int mid = (ss + se) / 2;

    int l = query( 2 *si, ss, mid, qs, qe);
    int r = query( 2 *si + 1, mid + 1, se, qs, qe);

    return min(l,r);
}



int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    int n, q, a, b;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
  
    
    buildTree(1, 1, n);
    cin >> q;

    while (q--)
    {
        cin >> a >> b;
        cout << query(1, 1, n, a+1, b+1) << endl;
    }
    
    
    return 0;
}
