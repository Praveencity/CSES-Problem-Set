// https://cses.fi/problemset/task/1669
#include <bits/stdc++.h>
using namespace std;

// Using Simple Circuit/ Cyclic
bool bfs(vector<vector<int>> &g, vector<int> &vis, int vertex)
{
    int path_1 = 0;
    int path_2 = 0;

    queue<int> q;
    q.push(vertex);
    vis[vertex] = -1;

    while(!q.empty())
    {
        int ver = q.front();
        q.pop();
        for(auto child: g[ver])
        {
            if(child == vis[ver]) continue;
            if(vis[child])
            {
                path_1 = child;
                path_2 = ver;
                break;
            }
            else
            {
                vis[child] = ver;
                q.push(child);
            }
        }
        if(path_1)
            break;
    }

   
    if(path_1 == 0)
        return false;

    vector<int> a,b;
    a.push_back(path_1);
    while(path_1!=vertex)
    {
        path_1 = vis[path_1];
        a.push_back(path_1);
    }
    b.push_back(path_2);
    while(path_2!=vertex)
    {
        path_2 = vis[path_2];
        b.push_back(path_2);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int idx = 0 ;
    for(int i=0;i<min(a.size(),b.size());i++)
    {
        if(a[i]!=b[i])
        
            break;
        idx = i;
    }
    for(int i=b.size()-1;i>=idx;--i)
        a.push_back(b[i]);

    cout << a.size()-idx << endl;
    for(int i=idx;i<a.size();i++)
        cout << a[i] << (i==a.size()-1 ? '\n' : ' ' );
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> g(n+1);
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        if(bfs(g,vis,i))
            return 0;
    }
    cout << "IMPOSSIBLE\n" ;
}