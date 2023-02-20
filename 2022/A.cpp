#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    v.push_back(0);
    v.push_back(1440);
    sort(v.begin(), v.end());

    int walk = 0;
    for(int i=0; i<n+1; i++){
        if(v[i+1] - v[i] >= 240){
            cout << "YES\n";
            return;
        } else if (v[i+1] - v[i] >= 120){
            walk++;
        }
        if(walk == 2){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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