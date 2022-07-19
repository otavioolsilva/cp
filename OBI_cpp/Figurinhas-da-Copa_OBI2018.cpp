#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, C, M, aux = 0;
    cin >> N >> C >> M;
    int x[C], y[M];

    for(int cont = 0; cont < C; cont++){
        cin >> x[cont];
    }

    for(int cont = 0; cont < M; cont++){
        cin >> y[cont];
        for(int contt = 0; contt < C; contt++){
            if(y[cont] == x[contt]){
                aux++;
                x[contt] = -1;
            }
        }
    }

    cout << C-aux << endl;

    return 0;
}
