#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;

void solve(){
    int n;
    cin >> n;
    bool st[1000002];
    memset(st, false, sizeof(st));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if (s.size() <= 6){
            int x = stoi(s);
            if(x >= 0 && x <= 1000000) st[x] = true;
        }
 
    }
    
    for(int x = 0; x <= 1000001; x++){
        if (st[x] == false){
            cout << x << "\n";
            return;
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}