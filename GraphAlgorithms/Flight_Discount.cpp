#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

const int inf = LLONG_MAX;

vector<int> dijkstra(const vector<vector<pair<int,int>>> &graph, int n, int start)
{
    vector<int> distance(n+1,inf);
    set<pair<int,int>> pq;
    pq.insert({0,start});
    distance[start] = 0;

    while(!pq.empty())
    {
        auto [wt_u,u] = *pq.begin();
        pq.erase(pq.begin());

        if(wt_u > distance[u]) continue;

        for(auto [v,wt_v] : graph[u])
        {
            int new_wt = wt_v + wt_u;
            if(new_wt < distance[v])
            {
                distance[v] = new_wt;
                pq.insert({new_wt,v});
            }
        }
    }

    return distance;
}

void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> graph(n+1),rev(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        graph[a].push_back({b,c});
        rev[b].push_back({a,c});
    }

    vector<int> start_point = dijkstra(graph, n, 1);
    vector<int> end_point = dijkstra(rev, n, n);

    int min_path = inf;
    for(int k=1;k<=n;k++)
    {
        for(auto [v,wt] : graph[k])
        {
            if(start_point[k] == inf || end_point[v] == inf) continue;
            min_path = min(min_path,start_point[k] + wt/2 + end_point[v]);
        }
    }

    cout << min_path << endl;
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
