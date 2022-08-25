#include <bits/stdc++.h>
using namespace std;
#define INF 100000
#define MAXN 109

int n, m; 
int notas[MAXN][MAXN]; //curso aluno
int q[MAXN];
int distance(int x, int y){
	int distance = 0;
	bool is_inf = 1;
	for(int i = 1; i <= m; i++){
		int n1 = notas[i][x], n2 = notas[i][y];
		if(n1 >= 0 && n2 >= 0){
			distance += (n1 - n2) * (n1 - n2);
			is_inf = 0;
		}

	}
	if(is_inf) distance = INF;
	return distance;
}

int melhorCurso(int x, int y){
	int maiorNota = -1;
	int melhorCur = -1;
	for(int i = 1; i <= m; i++){
		int n1 = notas[i][x], n2 = notas[i][y];
		if(!(n1 >= 0) && n2 > maiorNota){
			melhorCur = i;
			maiorNota = n2;
		}
	}
	return melhorCur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 1; j <= m; j++)
			notas[j][i] = -1;
	for(int i = 0; i < n; i++){
		cin >> q[i];
		for(int j = 0; j < q[i]; j++){
			int c, g;
			cin >> c >> g;
			notas[c][i] = g;
		}
	}
	for(int i = 0; i < n; i++){
		int mais_proximo;
		int menorDist = INF;
		for(int j = 0; j < n; j++){
			int distancia = distance(i, j);
			if(distancia < menorDist && i != j){
				menorDist = distancia;
				mais_proximo = j;
			}
		}
		cout << melhorCurso(i, mais_proximo) << endl;
	}
	
}