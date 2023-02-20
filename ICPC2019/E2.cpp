#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;



void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>>v(m);

    for(int i=0; i<m; i++){
        int amount;
        cin >> amount;
        v[i] = {amount, i+1};
    }

    sort(v.begin(), v.end(), greater<pair<int,int>>());
    vector<int>ans(n);
    int pos = 0, start = 0;
    for(auto [amount, index] : v){
        for (int i=0; i<amount; i++){
            if(pos != n-1 && ans[pos+1] == index){
                cout << "-1\n";
                return;
            }
            ans[pos] = index;
            pos += k+1;
            if (pos > n-1){
                start++;
                pos = start;
            }
        }
    }

    for(int a : ans) cout << a << " ";
    cout << el;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}