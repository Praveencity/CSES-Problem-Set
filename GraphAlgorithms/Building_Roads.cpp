// https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


const int N = 1e5+1;
vector<bool> vis(N);

// Using Connected Component
void bfs(vector<vector<int>> &g,int vertex)
{
    queue<int> q;
    q.push(vertex); 
    vis[vertex] = true;

    while(!q.empty())
    {
        int curr_ver = q.front();
        q.pop();
        for(auto child: g[curr_ver])
        {
            if(vis[child]) continue;
            q.push(child);
            vis[child] = true;
        }
    }
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

    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        bfs(g,i);
        ans.push_back(i);
    }
    cout << ans.size()-1 << endl; 
    for(int i=1;i<ans.size();i++)
        cout << ans[i-1] << ' ' << ans[i] << ' ';
    cout << endl;
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
// Using dfs -> https://cses.fi/problemset/result/14634840/