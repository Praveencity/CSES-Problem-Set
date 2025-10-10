// https://cses.fi/problemset/task/1668
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


const int N = 1e5+1;
vector<int> vis(N);

// Using Bipatatite
bool dfs(vector<vector<int>> &g,int vertex,int par)
{
    vis[vertex] = 3 - vis[par];
    bool is_partit = true;
    for(auto child : g[vertex])
    {
        if(vis[child] == vis[vertex]) return false;
        if(vis[child]) continue;
        is_partit &= dfs(g, child, vertex);
    }
    return is_partit;
}

void solve() {

    for(int i=0;i<N;i++) vis[i] = 0;

    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis[0] = 2;
    bool is_poss = true;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        is_poss &= dfs(g,i,0);
    }

    if(!is_poss)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for(int i=1;i<=n;i++)
        cout << vis[i] << (i == n ? '\n' : ' ');
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

// Using bfs -> https://cses.fi/problemset/result/14652992/
