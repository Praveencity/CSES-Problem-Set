#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int count = 0;
    int sum = 0;
    int l=0,r=n-1;
    while(l<r)
    {
        if(v[l]+v[r]<=x)
        {
            count++;
            l++;
            r--;
        }
        else
        {
            count++;
            r--;
        }
        
    }
    if(l==r)
        count++;
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
