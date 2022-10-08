#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    int t1 = abs(a-1);
    int t2;

    if(c < b){
        t2 = abs(b-1);
    }
    else{
        t2 = abs(c-b) + abs(c-1);
    }

    if(t1 > t2)cout << 2 << endl;
    else if(t2 > t1) cout << 1 << endl;
    else cout << 3 << endl;
}

int main(){
// #ifndef MYNK
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
