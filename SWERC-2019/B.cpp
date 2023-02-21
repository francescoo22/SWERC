#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;

void solve(){
    int n;
    cin >> n;
    map <string, int> m;
    int max = 0;
    string ans;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        m[s] ++;
    }
    for (auto x : m){
        if (x.second > (n - x.second)) {
            cout << x.first << el;
            return;
        }
    }
    cout << "NONE\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}