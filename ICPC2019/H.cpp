#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;

//#define DEBUG

#ifdef DEBUG
    #define rep(...) cout << __VA_ARGS__ ;
#else  
    #define rep(...)
#endif

void solve(){
    int n;
    cin>>n;
    vector<ll> pos(n);
    vector<unordered_map<ll,int>> memo(n);
    int maxL=-1;

    for (int i=0; i<n; ++i){
        cin>>pos[i];
        memo[i].reserve(i+10);

        for (int j=i-1; j>=0; --j){
          //  if (j+1<maxL) break;
            const ll dist=pos[i]-pos[j];
            const auto v = memo[i][dist]= 1+ (memo[j].count(dist) ? memo[j][dist] : 0);
            maxL = max(maxL, v+1);
            rep("memo ["<<i<<"]["<<dist<<"] = "<<memo[i][dist]<<"\n")
        }
    }

    cout<<maxL;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}