#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, aux = 0, qE = 0, qD = 0, contE = 0, contD = 0;
    cin >> N;
    int M[N], E[N], D[N];
    string L[N];

    //leitura de dados e assimilacao para E e D
    for(int cont = 0; cont < N; cont++){
        cin >> M[cont] >> L[cont];
        if(L[cont] == "E"){
            E[qE] = M[cont];
            qE++;
        } else if(L[cont] == "D"){
            D[qD] = M[cont];
            qD++;
        }
    }

    //sort
    sort(E,E+qE);
    sort(D,D+qD);

    //formacao de pares
    while(contE < qE && contD < qD){
        if(E[contE] == D[contD]){
            aux++;
            contE++;
            contD++;
        } else if(E[contE] < D[contD]){
            contE++;
        } else if(D[contD] < E[contE]){
            contD++;
        }
    }

    //print
    cout << aux << endl;

    return 0;
}
