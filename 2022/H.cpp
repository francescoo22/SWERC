#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n;
    cin >> n;
    vector<int> pos(n), v1(n), v2(n);
    for(int i=0; i<n; i++){
        cin >> v1[i];
        v1[i]--;
    }
    for(int i=0; i<n; i++){
        cin >> v2[i];
        v2[i]--;
        pos[v2[i]] = i;
    }
    int current = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(pos[v1[i]] > current) ans = current = pos[v1[i]];
        if(pos[v1[i]] == current) current++;
    }

    cout << ans << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}