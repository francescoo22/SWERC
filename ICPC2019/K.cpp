#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;



void solve(){
    int n;
    cin>>n;

    cout<< (n*n*3/4)<<"\n";
    for (int i=n-1; i>0; i-=2){
        for (int j=1; j<=n; j+=2){
            cout<<"1 "<<i<<" "<<j<<" 1\n";
            cout<<"1 "<<i+1<<" "<<j+1<<" 1\n";
            cout<<"2 "<<i<<" "<<j<<" 2\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}