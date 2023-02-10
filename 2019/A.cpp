#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;

struct Edge {
    int to, co2, dist;
};

class Node {
public:
    int x, y;
    vector <Edge> adj; 

    void add (int to, int mode){
        adj.push_back({to, mode, mode});
        
    }
};

void solve(){
    int xs, ys; // house
    cin >> xs >> ys;

    int xd, yd; // destination
    cin >> xd >> yd;

    int b, c0; // max distance and car cost
    cin >> b >> c0;

    int t; // types of transport
    cin >> t;

    vector<int> costs(t+1);
    costs[0] = c0;
    for(int i=0; i<t;i++) cin >> costs[i+1];

    int n; //number of station
    cin >> n;

    vector<Node> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].x;
        cin >> v[i].y;
        int l;
        cin >> l;
        for(int j=0; j<l; j++){
            int to, mode;
            cin >> to >> mode;
            v[i].add(to, mode);
            v[to].add(i, mode);
        }
    }

    // *** end parsing ***

    cout << "ok";
}

int main() {
    Edge e = Edge{1, 2, 3};
    auto [ to, co2, dist ] = e;
    // cout << x << y << z;
    return 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}