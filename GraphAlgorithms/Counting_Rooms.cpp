// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1010;
int vis[N][N];
 
vector<pair<int,int>> movements = {{1,0},{-1,0},{0,1},{0,-1}};
 
void bfs(vector<vector<char>> &matrix, int i, int j, int n, int m)
{
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j] = 1;
 
    while(!q.empty())
    {
        auto [a,b] = q.front();
        q.pop();
        for(auto [x,y]:movements)
        {
            int v1 = x+a;
            int v2 = y+b;
            if(v1 < 0 || v2<0 || v1>=n || v2>=m) continue;
            if(vis[v1][v2]) continue;
            if(matrix[v1][v2] == '#') continue;
            q.push({v1,v2});
            vis[v1][v2] = 1;
        }
    }
 
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }
    
    int count_room = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='#' || vis[i][j]) continue;
            count_room++;
            bfs(matrix, i, j, n, m);
        }
    }
    cout << count_room << endl;
}

// Using dfs -> https://cses.fi/problemset/result/14586783/