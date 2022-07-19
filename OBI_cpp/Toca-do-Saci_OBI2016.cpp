#include <bits/stdc++.h>
using namespace std;

int pos[1010][1010];

int main()
{
    int N, M, r = 1;
    scanf("%d %d", &N, &M);
    int x2, y2;

    for(int contY = 1; contY <= N; contY++){
        for(int contX = 1; contX <= M; contX++){
            scanf("%d", &pos[contX][contY]);
            if(pos[contX][contY] == 2){
                x2 = contX;
                y2 = contY;
            }
        }
    }

    int  auxx2 = x2, auxy2 = y2;

    while(1){
        if(pos[auxx2-1][auxy2] == 1){ //PARA ESQUERDA
            pos[auxx2-1][auxy2] = 0;
            auxx2 -= 1;
            r++;
        } else if(pos[auxx2+1][auxy2] == 1){ //PARA DIREITA
            pos[auxx2+1][auxy2] = 0;
            auxx2 += 1;
            r++;
        } else if(pos[auxx2][auxy2-1] == 1){ //PARA CIMA
            pos[auxx2][auxy2-1] = 0;
            auxy2 -= 1;
            r++;
        } else if(pos[auxx2][auxy2+1] == 1){ //PARA BAIXO
            pos[auxx2][auxy2+1] = 0;
            auxy2 += 1;
            r++;
        } else if(pos[auxx2-1][auxy2] == 3 || pos[auxx2+1][auxy2] == 3 || pos[auxx2][auxy2-1] == 3 || pos[auxx2][auxy2+1] == 3) { //SE ACHAR 3
            r++;
            break;
        } else { //FALHOU, RESETANDO TUDO E VOLTANDO DO COMEÇO
            auxx2 = x2;
            auxy2 = y2;
            r = 1;
        }
    }

    printf("%d\n", r);

    return 0;
}
