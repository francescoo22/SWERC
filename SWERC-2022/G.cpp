#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;
using ii = pair<int, int>;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    int temp_ans = 0;
    for(int i=0; i<n; i++){
        if (s[i] == 'W') ans++;
    }
    temp_ans = ans;
    for(int i=n; i<s.size(); i++){
        if(s[i-n] == 'W') temp_ans--;
        if(s[i] == 'W') temp_ans++;
        ans = max(ans, temp_ans);
    }

    cout << ans << el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}