#include <bits/stdc++.h>
using namespace std;

//Baseado na lógica da solução shi.cpp (disponível no site da OBI)
bool e[100001], d[100001];

int main()
{
    int N, aux = 0, result = 0;
    scanf("%d", &N);

    int H[N];
    for(int cont = 0; cont < N; cont++)
        scanf("%d", &H[cont]);

    aux = H[0];
    for(int cont = 1; cont < N; cont++){
        if(H[cont] < aux) e[cont] = true;
        else aux = H[cont];
    }

    aux = H[N-1];
    for(int cont = N-2; cont >= 0; cont--){
        if(H[cont] < aux) d[cont] = true;
        else aux = H[cont];
    }

    for(int cont = 1; cont < N-1; cont++)
        if(e[cont] == true && d[cont] == true) result++;

    printf("%d\n", result);

    return 0;
}
