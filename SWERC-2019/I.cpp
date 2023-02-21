#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;

void solve(){
    double n1, n2, n12;
    cin >> n1 >> n2>> n12;
    double ans = floor ((n1+1)*(n2+1)/(n12+1)-1);
    cout << ans << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}