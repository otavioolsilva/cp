#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D, result = 0;
    scanf("%d %d", &N, &D);
    int C[N*2];

    for(int cont = 0; cont < N; cont++){
        scanf("%d", &C[cont]);
        C[cont+N] = C[cont];
    }

    int soma = 0, contt = 0;
    for(int aux = 0; aux < N; aux++){
        while(soma < D){
            if(contt == aux+N) break;
            soma = soma + C[contt];
            contt++;
        }
        if(soma == D){
            result++;
            soma = soma - C[aux];
        }
        else soma = soma - C[aux];
    }

    printf("%d\n", result);

    return 0;
}
