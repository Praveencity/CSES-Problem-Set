// https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

vector<pair<int,int>> movements = {{1,0},{-1,0},{0,1},{0,-1}};
vector<char> dir = {'D','U','R','L'};


void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> matrix(n , vector<char> (m,0));
    pair<int,int> start, end;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
            if(matrix[i][j]=='A')
            {
                start.first = i;
                start.second = j;
            }
            if(matrix[i][j]=='B')
            {
                end.first = i;
                end.second = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m,false));
    vector<vector<char>> direction(n+1, vector<char> (m+1,0));
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    
    bool found = false;
    while(!q.empty() && !found)
    {
        auto [a,b] = q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            int x = a + movements[k].first;
            int y = b + movements[k].second;
            if(x<0 || y<0 || x>=n || y>=m) continue;
            if(vis[x][y] || (matrix[x][y]=='#')) continue;
            direction[x][y] = dir[k];
            q.push({x,y});
            vis[x][y] = true;
            if(matrix[x][y] == 'B')
            {
                found = true;
                break;
            }
        }
    }

    if(!found)
    {
        cout << "NO\n";
        return;
    }

    string ans = "";
    pair<int,int> curr_loc = end;
    while(curr_loc != start)
    {
        char d = direction[curr_loc.first][curr_loc.second];
        int idx = find(dir.begin(),dir.end(),d) - dir.begin();
        pair<int,int> mov = movements[idx];
        curr_loc.first -= mov.first; 
        curr_loc.second -= mov.second; 
        ans.push_back(d);
    }

    reverse(ans.begin(),ans.end());

    cout << "YES\n";
    cout << ans.size() << endl;
    cout << ans << endl;

}

int32_t main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    solve();
    return 0;
}
