#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;



void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> a_sopra, b_sopra;

    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            if(a[i] == 'a') a_sopra.push_back(i+1);
            else b_sopra.push_back(i+1);
        }
    }

    if (a_sopra.size() % 2 != b_sopra.size() % 2){
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> ans;
    int la, lb;
    // for(auto x:a_sopra) cout << x << " ";
    // cout << el;
    // for(auto x:b_sopra) cout << x << " ";
    // cout << el;
    if (a_sopra.size() % 2 == 1){
        la = a_sopra.back();
        lb = b_sopra.back();
        ans.push_back({lb, lb});
        ans.push_back({lb, la});
        a_sopra.pop_back();
        b_sopra.pop_back();
    } 

    for(int i=0; i< a_sopra.size(); i+=2){
        ans.push_back({a_sopra[i], a_sopra[i+1]});
    }

    for(int i=0; i< b_sopra.size(); i+=2){
        ans.push_back({b_sopra[i], b_sopra[i+1]});
    }

    cout << ans.size() << el;

    for(auto [x, y] : ans){
        cout << x << " " << y << el;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}