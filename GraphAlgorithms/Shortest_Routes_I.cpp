// https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Using Dijkstra Algorithm
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> weight(n+1,LLONG_MAX);
    vector<pair<int,int>> g[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        g[a].push_back({b,c});

    }

    multiset<pair<int,int>> ms;
    ms.insert({0,1});
    weight[1] = 0;

    while(!ms.empty())
    {
        auto [wt,v] = *ms.begin();
        ms.erase(ms.begin());
        if(wt > weight[v]) continue;
        for(auto [b,c] : g[v])
        {
            int new_wt = wt + c;
            if(new_wt < weight[b])
            {
                weight[b] = new_wt;
                ms.insert({new_wt,b});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout << weight[i] << (i==n ? '\n' : ' ');
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
