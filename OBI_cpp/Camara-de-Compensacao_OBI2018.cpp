#include <bits/stdc++.h>
using namespace std;

int S[1010];

int main(){

    int M, N, aux = 0, total = 0, tSoma = 0, x, y, v;

    scanf("%d %d", &M, &N);

    for(int cont = 1; cont <= M; cont++){
        scanf("%d %d %d", &x, &v, &y);
        S[x] = S[x] - v;
        S[y] = S[y] + v;
        total = total + v;
    }

    for(int cont = 1; cont <= N; cont++){
        if(S[cont] > 0) tSoma = tSoma + S[cont];
    }

    if(total == tSoma){
        cout << "N" << endl;
        cout << total << endl;
    } else {
        cout << "S" << endl;
        cout << tSoma << endl;
    }

    return 0;
}
