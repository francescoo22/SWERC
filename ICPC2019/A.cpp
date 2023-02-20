#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;



void solve(){
    ll a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;

    ll _min= max(0ll, n-(a1*(k1-1) + a2*(k2-1)));
    if (k1>k2){
        swap(k1,k2);
        swap(a1,a2);
    }
    ll _max= n/k1;
    if (_max>a1){
        n-= a1*k1;
        _max= a1+n/k2;
    }

    cout<<_min<<" "<<_max;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}