#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<ll, ll, ll>;
using ii = pair<ll, ll>;

string seq;
int piu = 0, meno = 0;

void solve(){
    int a, b;
    cin >> a >> b;

    if (piu == meno){
        cout << "YES\n";
        return;
    }

    int mcd = gcd(a, b);
    a /= mcd;
    b /= mcd;

    int i=1;
    while(a*i <= piu && b*i <= meno){
        if(piu - a*i == meno - b*i){
            cout << "YES\n";
            return;
        }
        i++;
    }

    i=1;
    swap(a, b);
    while(a*i <= piu && b*i <= meno){
        if(piu - a*i == meno - b*i){
            cout << "YES\n";
            return;
        }
        i++;
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cin >> seq;

    for(char c : seq){
        if (c == '+') piu++;
        else meno++;
    }

    cin >> t;
    while(t--)
        solve();
    return 0;
}