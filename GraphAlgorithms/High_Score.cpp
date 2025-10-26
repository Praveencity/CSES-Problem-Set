#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

struct Edge{
    int a, b, cost;
};

// Using Modified Bellman Ford and BFS
void solve() {
    int n,m;
    cin>>n>>m;

    vector<Edge> edges;
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> dist(n+1,LLONG_MIN);
    dist[1] = 0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
        g[a].push_back({b,c});
    }

    for(int i=0;i<n-1;i++)
    {
        for(Edge &e : edges)
            if(dist[e.a]!=LLONG_MIN && dist[e.b] < dist[e.a]+e.cost)
                dist[e.b] = dist[e.a]+e.cost;
    }
    
    if(dist[n]==LLONG_MIN)
    {
        cout << -1 << endl;
        return;
    }
    
    set<int> cycle_edges;
    for(Edge &e : edges)
        if(dist[e.a]!=LLONG_MIN && dist[e.b] < dist[e.a]+e.cost)
            cycle_edges.insert(e.b);
    
    vector<int> vis(n+1,0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    queue<int> q_cycle_edges;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(cycle_edges.count(u))
            q_cycle_edges.push(u);

        for(auto [v,wt] : g[u])
        {
            if(vis[v]) continue;
            q.push(v);
            vis[v] = 1;
        }
    }

    bool is_pos = false;
    fill(vis.begin(),vis.end(),0);
    while(!q_cycle_edges.empty())
    {
        int u = q_cycle_edges.front();
        q_cycle_edges.pop();

        if(u==n)
        {
            is_pos = true;
            break;
        }

        for(auto [v,wt] : g[u])
        {
            if(vis[v]) continue;
            q_cycle_edges.push(v);
            vis[v] = 1;
        }
    }

    if(is_pos)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;

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
