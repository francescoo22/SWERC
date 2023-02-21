#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<ll, ll, ll>;
using ii = pair<ll, ll>;

ll triangle_2area(ii a, ii b, ii c){
    ll area = 0;
    area += (a.second + b.second) * (b.first - a.first);
    area += (b.second + c.second) * (c.first - b.first);
    area += (a.second + c.second) * (a.first - c.first);

    return abs(area);
}

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    vector<iii> v2(n);
    for(ll i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        v[i] = {x, y};
        v2[i] = {x, y, i+1};
    }

    ll a = 0, b = 0;
    for(ll i=0; i<n-2; i++){
        ll sz = v.size(), min_index;
        ll min_area = LONG_LONG_MAX;
        for(ll j=0; j<sz; j++){
            ll area = triangle_2area(v[j], v[(j+1)%sz], v[(j+2)%sz]);
            if (area < min_area){
                min_area = area;
                min_index = (j+1) % sz;
            }
        }
        v.erase(v.begin() + min_index);
        if (i % 2 == 0) a += min_area;
        else b += min_area;
    }
    cout << (a < b ? "Alberto" : "Beatrice") << endl;

    bool my_turn = a < b;
    while(v2.size() > 2){
        ll sz = v2.size();
        if (my_turn){
            ll min_area = LONG_LONG_MAX, min_index;
            for(ll j=0; j<sz; j++){
                auto [x1, y1, i1] = v2[j];
                auto [x2, y2, i2] = v2[(j+1)%sz];
                auto [x3, y3, i3] = v2[(j+2)%sz];
                ll area = triangle_2area({x1, y1}, {x2, y2}, {x3, y3});
                if (area < min_area){
                    min_area = area;
                    min_index = (j+1) % sz;
                }
            }
            cout << get<2>(v2[min_index]) << endl;
            v2.erase(v2.begin() + min_index);

        } else {
            ll index;
            cin >> index;
            for(ll i=0; i<sz; i++){
                if (get<2>(v2[i]) == index){
                    v2.erase(v2.begin() + i);
                    break;
                }
            }
        }

        my_turn = !my_turn;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}