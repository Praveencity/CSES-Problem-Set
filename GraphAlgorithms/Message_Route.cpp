// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Using BFS
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> vis_prev(n+1,0);

    queue<int> q;
    q.push(1);
    vis_prev[1] = -1;
    bool found = false;
    while(!q.empty() && !found)
    {
        int vertex = q.front();
        q.pop();
        for(auto child: g[vertex])
        {
            if(vis_prev[child]) continue;
            q.push(child);
            vis_prev[child] = vertex;
            if(child == n)
            {
                found = true;
                break;
            }
        }
    }

    if(!vis_prev[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int node = n;
    vector<int> ans;
    ans.push_back(n);
    while(vis_prev[node]!=-1)
    {
        node = vis_prev[node];
        ans.push_back(node);
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << ' ';
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
