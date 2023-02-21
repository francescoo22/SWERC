#include <bits/stdc++.h>
#define ll long long int
#define el "\n"
using namespace std;
using iii = tuple<int, int, int>;



void solve(){
    ll n;
    ll o_a,o_b=0, o_c=0;
    ll c_pos=0, c_neg=-1;
    ll b_cont=0, b_delta=0;
    bool isPos=true;

    cin>>n;

    for (int i=0; i<n; ++i){
        ll in;
        cin>>in;

        if (in==0){
            //o_b
            b_delta+=b_cont+1;
            b_cont=0;

            //o_c
            c_pos=0; c_neg=-1;
            isPos=true;
        }
        else {
            //o_b
            b_cont++;

            //o_c
            if (in<0){
                isPos= !isPos;
            }

            if (isPos){
                c_pos++;
                o_c+=c_pos;
            } else {
                c_neg++;
                o_c+=c_neg;
            }
            
        }
        

        o_b+=b_delta;

   //     cout<<"\n"<<c_pos<<" "<<c_neg<<" "<<o_c<<"\n";
   //     cout<<"\n"<<b_cont<<" "<<b_delta<<" "<<o_b<<"\n";
    }


    o_a= n*(n+1)/2 - o_b - o_c;

    cout<<o_a<<" "<<o_b<<" "<<o_c<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}