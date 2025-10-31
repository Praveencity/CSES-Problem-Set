#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


void solve() {
    int n;
    cin>>n;
 
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
 
        s.insert(a);
    }
 
    cout << s.size() << '\n';
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
