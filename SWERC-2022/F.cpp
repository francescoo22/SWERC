#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<iii> edges; // da a colore

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges.push_back({u, v, 1});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        auto v = adj[i];
        if(v.size() < n-1){
            cout << "2\n";
            for(auto [u, v, color] : edges){
                if (u == i || v == i) cout << "2 ";
                else cout << "1 ";
            }
            cout << el;
            return;
        }
    }

    cout << "3\n";
    for(auto [u, v, color] : edges){
        if (u == 0 || v == 0){
            if (u == 1 || v == 1)  cout << "3 ";
            else cout << "2 ";
        }
        else cout << "1 ";
    }
    cout << el;
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