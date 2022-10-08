#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

void solve() {
    int r,c,q;
    cin >> r >> c >> q;
    vector<ll> row, col;
    while(q--){
        ll p,q;
        cin >> p >> q;
        row.push_back(p);
        col.push_back(q);
    }

    row.push_back(0);
    row.push_back(r + 1);

    col.push_back(0);
    col.push_back(c + 1);

    sort(row.begin(),row.end());
    sort(col.begin(),col.end());

    ll mxr = -1e18, mxc = -1e18;

    for(int i=0;i<row.size()-1;i++){
        mxr = max(mxr,row[i+1] - row[i] - 1);
    }

    for(int i=0;i<col.size()-1;i++){
        mxc = max(mxc,col[i+1] - col[i] - 1);
    }

    // cout << mxr << " " << mxc << endl;

    cout << mxr * mxc << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
