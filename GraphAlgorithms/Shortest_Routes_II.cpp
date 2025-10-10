// https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Using Foryd warshell
void solve() {
    int n, m, q;
    cin>>n>>m>>q;

    vector<vector<int>> g(n+1, vector<int> (n+1,LLONG_MAX));
    for(int i=0;i<=n;i++)
        g[i][i] = 0;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        g[a][b] = min(g[a][b],c);
        g[b][a] = min(g[b][a],c);
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][k] != LLONG_MAX && g[k][j] != LLONG_MAX)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);

    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(g[a][b] >= LLONG_MAX)
            cout << -1 << endl;
        else
            cout << g[a][b] << endl;
    }
    
}

int32_t main() {
    fast_io;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
