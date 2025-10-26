// https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

vector<pair<int,int>> cord = {{1,0},{-1,0},{0,1},{0,-1}};
vector<char> direction = {'D','U','R','L'};

// Using MultiSource bfs
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vector<char>> matrix(n, vector<char> (m));
    pair<int,int> start;
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
        }
    }

    vector<vector<int>> monster_time(n, vector<int> (m, LLONG_MAX));
    vector<vector<int>> vis(n, vector<int> (m));
    vector<vector<char>> path(n, vector<char> (m));
    
    
    queue<pair<int,int>> mq;
    for(int i=0;i<n;i++)
    {
        for(int j= 0;j<m;j++)
        {
            if(matrix[i][j] == 'M')
            {
                monster_time[i][j] = 1;
                mq.push({i,j});
            }
        }
    }

    while(!mq.empty())
    {
        auto [a,b] = mq.front();
        mq.pop();

        for(int i=0; i<4; i++)
        {
            int new_a = a + cord[i].first;
            int new_b = b + cord[i].second;
            if(new_a < 0 || new_b < 0 || new_a >= n || new_b >= m || matrix[new_a][new_b] == '#') continue;
            if(monster_time[new_a][new_b] > monster_time[a][b]+1)
            {
                monster_time[new_a][new_b] = monster_time[a][b]+1;
                mq.push({new_a,new_b});
            }
        }
    }

    pair<int,int> end = {-1,-1};

    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    vis[start.first][start.second] = 1;

    while(!q.empty())
    {
        auto [a,b] = q.front();
        q.pop();
        bool found = false;
        for(int i=0;i<4;i++)
        {
            int new_x = a+cord[i].first;
            int new_y = b+cord[i].second;
            if(new_x<0 || new_y<0 || new_x>=n || new_y>=m)
            {
                found = true;
                break;
            }
            if(vis[new_x][new_y] || matrix[new_x][new_y]=='M' || matrix[new_x][new_y]=='#') continue;
            vis[new_x][new_y] = vis[a][b]+1;
            if(vis[new_x][new_y] < monster_time[new_x][new_y])
            {
                path[new_x][new_y] = direction[i];
                q.push({new_x,new_y});
            }
        }
        if(found)
        {
            end.first = a;
            end.second = b;
            break;
        }
    }
    
    if(end.first == -1)
    {
        cout << "NO\n";
        return;
    }

    vector<char> ans_path;

    while(end != start)
    {
        char dir = path[end.first][end.second];
        ans_path.push_back(dir);
        int idx = find(direction.begin(),direction.end(),dir) - direction.begin();
        end.first -= cord[idx].first;
        end.second -= cord[idx].second;
    }

    reverse(ans_path.begin(),ans_path.end());
    cout << "YES\n";
    cout << ans_path.size() << endl;
    for(int i=0;i<ans_path.size();i++)
        cout << ans_path[i];

    cout << '\n';

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
