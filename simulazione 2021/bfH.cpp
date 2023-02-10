#include <bits/stdc++.h>
#define ll long long int
using namespace std;
set <int> ans;

void print_sol() {
    cout << ans.size() << " ";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << "\n";
    ans.clear();
}

bool bf (int i, int w, int l){
    bool ok = true;
    while(ok){
        
    }
}

void solve() {
    int w, l;
    cin >> w >> l;

    for (int i = 1; i<min(w, l); i++) {
        if (bf(i, w, l)) {
            ans.insert(i);
        }
    }

    print_sol();
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
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