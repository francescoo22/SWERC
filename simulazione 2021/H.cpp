#include <bits/stdc++.h>
#define ll long long int
using namespace std;
set <long long int> ans;

void print_sol() {
    cout << ans.size() << " ";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
    ans.clear();
}

void push_ans (ll x, ll y){
    ll start;
    ll max_n = max(x, y);
    
    if (x == y) {
        ans.insert(x);
        start = (ll) sqrt(x);
    } else {
        start = (ll) sqrt(max_n);
    }

    for(ll i = start; i>=1; i--){
        if (x % i == 0 && y % i == 0) {
            ans.insert(i);
        }
        if (max_n % i == 0) {
            ll j = max_n / i;
            if (x % j == 0 && y % j == 0) {
                ans.insert(j);
            }
        }
    }
}

void push_ans (ll x, ll y, ll z){
    ll start;
    ll max_n = max(x, max(y, z));
    if (x == y && y == z) {
        ans.insert(x);
        start = (ll) sqrt(x);
    } else {
        start = (ll) sqrt(max_n);
    }

    for(ll i = start; i>=1; i--){
        if (x % i == 0 && y % i == 0 && z % i == 0) {
            ans.insert(i);
        }
        if (max_n % i == 0) {
            ll j = max_n / i;
            if (x % j == 0 && y % j == 0 && z % j == 0) {
                ans.insert(j);
            }
        }
    }
}

void solve() {
    ll w, l;
    cin >> w >> l;
    push_ans(w-1, l-1);
    push_ans(w-2, l);
    push_ans(w, l-2);
    push_ans(w, w-2, l-1);
    push_ans(l, l-2, w-1);

    print_sol();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
1000000001
500000001
*/