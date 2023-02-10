#include <bits/stdc++.h>
using namespace std;
struct Nodo;
vector<Nodo> grafo;
struct Nodo{
    vector<int> vicini;
    bool colore=false;
    int uscita=-1;
    int visit=0;
};

int main(){
    int N,M,T;
    cin>>N>>M>>T;
    grafo.resize(N);
    int a,b;
    for (int i=0; i<M; ++i){
        cin>>a>>b;
        grafo[b].vicini.push_back(a);
    }

    queue<int> coda;
    for (auto i: grafo[T].vicini){
        coda.push(i);
        grafo[i].uscita=i;
    }
    while(!coda.empty()){
        int iAtt=coda.front();
        coda.pop();
        if (grafo[iAtt].colore){
            if (grafo[iAtt].visit==2){
                continue;
            } else {
                grafo[iAtt].visit=2;
            }
        }
        else {
                
            if (grafo[iAtt].visit){
                continue;
            }
            grafo[iAtt].visit=1;
        }


        for (auto j: grafo[iAtt].vicini){
            if (j==T) continue;
            if (grafo[iAtt].colore){
                grafo[j].colore=true;
                coda.push(j);
            } else {
                if (grafo[j].uscita==-1){
                    grafo[j].uscita=grafo[iAtt].uscita;
                    coda.push(j);
                } else if (grafo[j].uscita!=grafo[iAtt].uscita){
                    grafo[j].colore=true;
                    coda.push(j);
                }
            }
        }


    }

    vector<int> rit;
    for (auto i: grafo[T].vicini){
        if (!grafo[i].colore){
            rit.push_back(i);
        }
    }

    sort(rit.begin(),rit.end());

    cout<<rit.size()<<"\n";
    for (auto i: rit){
        cout<<i<<"\n";
    }
}