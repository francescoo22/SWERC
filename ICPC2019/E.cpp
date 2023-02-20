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
    priority_queue<pair<int,int>> coda;
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> out;
    out.reserve(n);
    int nSfori=0;

    for (int i=0; i<m; ++i){
        int a;
        cin>>a;
        coda.emplace(a,i+1);
        if (a>k) nSfori++;
    }

   // int i;
    pair<int,int> cache{-1,-1};
    for (; out.size()<n;){
        if (cache.first!=-1){
            rep("\nInserisco "<<cache.first<<", "<<cache.second<<"\n")
            rep("out.size() = "<<out.size()<<"\n")
            coda.push(cache);
            cache={-1,-1};
        }
        auto sopra=coda.top();
        if (!out.empty() && out.back() == sopra.second){
            cache=sopra;
            rep("\nCacho "<<cache.first<<", "<<cache.second<<"\n")
            rep("out.size() = "<<out.size()<<"\n")
            coda.pop();

            if (coda.empty()){
                cout<<-1;
                return;
            }
            sopra=coda.top();
            rep("Ora sopra = "<<sopra.first<<", "<<sopra.second<<"\n")
        }


        if (sopra.first<=k){
            coda.pop();
            for (int j=0; j<(nSfori>0 ? 1 : sopra.first); ++j){
                out.push_back(sopra.second);
            }
        } else {
            coda.pop();

            for (int j=0; j<k; ++j){
                
                out.push_back(sopra.second);
       //         ++i;
             //   if (i>=n) return;
            }


            coda.emplace(sopra.first-k, sopra.second);
            if (sopra.first-k <= k){
                nSfori--;
            }
      /*/      if (coda.empty()) continue;


            auto sopra2=coda.top();

            if (sopra2.first<=k){
                out.push_back(sopra2.second);


                coda.pop();
                if(sopra2.first>1)
                    coda.emplace(sopra2.first-1, sopra2.second);
            }
            */
        }
    }

    if (out.size() != n){
        cout<<-1;
        return;
    }
    for (auto i: out){
        cout<<i<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}