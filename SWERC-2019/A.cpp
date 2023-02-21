#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;

struct Edge {
    int co2, dist, to;
};

class Node;
vector<Node> v;

class Node {
public:
    int x, y;
    vector <Edge> adj; 

    Node(int xp=0, int yp=0){
        x = xp;
        y = yp;        
    }

    int euclidean_dist (const Node &n){
        return ceil(sqrt((x - n.x)*(x - n.x) + (y - n.y)*(y - n.y)));
    }

    void add (int to, int mode_cost){
        // da calcolare        
        int dist = euclidean_dist(v[to]);
        int co2 = mode_cost*dist;
        adj.push_back({co2, dist, to});       
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

    v.resize(n);
    vector<iii> temp; // da a costs[mode]
    for(int i=0; i<n; i++){
        cin >> v[i].x;
        cin >> v[i].y;
        int l;
        cin >> l;
        for(int j=0; j<l; j++){
            int to, mode;
            cin >> to >> mode;
            temp.push_back({i, to, costs[mode]});
        }
    }

    for (auto x : temp){
            auto [i, to, cost] = x;
            v[i].add(to, cost);
            v[to].add(i, cost);
    }
    temp.clear();

    // adding start and end

    v.push_back(Node(xs, ys));
    v.push_back(Node(xd, yd));
    v[n].add(n+1, costs[0]);
    for (int i=0; i<n; i++){
        v[n].add(i, costs[0]);
        v[i].add(n+1, costs[0]);
    }

    priority_queue <iii, vector<iii>, greater<iii>> pq; // co2, dist, node

    pq.push({0,0,n});
    vector<int> min_dist(n+2, INT_MAX);

    while(!pq.empty()){
        auto [co2_curr, dist_curr, node] = pq.top();
        
        pq.pop();

        if (node == n+1){
            cout << co2_curr << el;
            return;
        }

        if (min_dist[node] <= dist_curr) continue;
        min_dist[node] = min(dist_curr,min_dist[node]);

        for(auto x : v[node].adj){
            auto [co2_cost, dist_cost, to] = x;
            
            if(dist_curr + dist_cost <= b) {
                pq.push({co2_curr + co2_cost, dist_curr + dist_cost, to});

            }
        }
    }

    cout << -1 << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}