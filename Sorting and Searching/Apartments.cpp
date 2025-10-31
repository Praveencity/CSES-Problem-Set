#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<int> a(n);
    for(auto &x:a)
        cin>>x;

    vector<int> b(m);
    for(auto &x:b)
        cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int i=0,j=0;
    int count = 0;
    while(i<n && j<m)
    {
        if(abs(a[i]-b[j])<=k)
        {
            i++;
            j++;
            count++;
            continue;
        }

        if(a[i]-b[j] > k)
            j++;
        else
            i++;
    }
    cout << count << endl;

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
