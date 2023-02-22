#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

int n, h;
vector<int> v;
vector<vector<int>> memo;

int H(int l, int r){
    int x1 = v[l];
    int x2 = v[r];

    int to_join =  (x2 - x1 + 1) / 2 - 1;

    return max(0, h - to_join);
}

int dp (int l, int r){
    if(memo[l][r] != -1) return memo[l][r];

    if(l == r) return h;

    int ans = INT_MAX;
    for(int i=l; i<r; i++){
        ans = min(ans, dp(l, i) + dp(i+1, r));
    }
    ans -= H(l, r);

    memo[l][r] = ans;
    return ans;
}

void solve(){
    cin >> n >> h;
    v.resize(n);
    memo.resize(n, vector<int>(n, -1));

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << dp(0, n-1) << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}