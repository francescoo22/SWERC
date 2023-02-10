#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct CircularWall {
    int r, t1, t2;
    CircularWall(int r_, int t1_, int t2_) {
        r = r_;
        t1 = t1_;
        t2 = t2_;
    }
    bool operator < (const CircularWall& cw) const {
        return r < cw.r;
    }
};

struct StraightWall {
    int r1, r2, t;
    StraightWall(int r1_, int r2_, int t_) {
        r1 = r1_;
        r2 = r2_;
        t = t_;
    }
    bool operator < (const StraightWall& sw) const {
        return t < sw.t;
    }
};

struct Node {
    int t1, t2;
    Node(int t1_=0, int t2_=0) {
        t1 = t1_;
        t2 = t2_;
    }
};

void solve() {
    int n;
    cin >> n;
    vector <CircularWall> cw;
    vector <StraightWall> sw;
    for (int i = 0; i<n; i++) {
        char c;
        cin >> c;
        if (c == 'C') {
            int r, t1, t2;
            cin >> r >> t1 >> t2;
            cw.push_back(CircularWall(r, t1, t2));
        } else {
            int r1, r2, t;
            cin >> r1 >> r2 >> t;
            sw.push_back(StraightWall(r1, r2, t));
        }
    }
    sort(cw.begin(), cw.end());
    sort(sw.begin(), sw.end());

    // todo compatta i cerchi

    vector <Node> regions[21];

    for (int i = 1; i <= 20; i++){
        set <int> thetas;
        for (auto s : sw) {
            if (s.r1  < i && s.r2 >= i) {
                thetas.insert(s.t);
            }
        }
        
        if (thetas.size() <= 1) {
            regions[i].push_back(Node(0, 360));
            continue;
        }

        int prev = *thetas.rbegin();

        for (auto theta : thetas) {
            regions[i].push_back(Node(prev, theta));
            prev = theta;
        }
    }

    for (int i = 1; i <= 20; i++) {
        
    }

    // for (int i = 1; i <= 20; i++) {
    //     cout << "i: " << i << endl;
    //     for (auto r : regions[i]) {
    //         cout << r.t1 << " " << r.t2 << endl;
    //     }
    // }
    
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