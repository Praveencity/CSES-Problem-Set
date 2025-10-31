#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


void solve() {
    int n,m;
    cin>>n>>m;

    multiset<int> a;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        a.insert(v);
    }

    for(int i=0;i<m;i++)
    {
        int v;
        cin>>v;
        auto it = a.upper_bound(v);
        if(it==a.begin())
            cout << -1 << endl;
        else
        {
            cout << *(--it) << endl;
            a.erase(it);
        }
    }  
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
