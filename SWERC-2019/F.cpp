#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;

ll double_area (pair<ll,ll> coord1, pair<ll,ll> coord2){
    ll h = coord1.first - coord2.first;
    ll somma_basi = coord1.second + coord2.second;
    return somma_basi * h;
}

ll solve(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> coords;
    for(ll i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        coords.push_back({x, y});
    }
    ll ans = 0;
    for (ll i=0; i < n; i++){
        ans += double_area(coords[i], coords[(i+1)%n]);
    }
    return abs(ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += solve();
    }
    cout << ans / 2;
    return 0;
}