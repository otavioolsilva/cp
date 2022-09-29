#include <bits/stdc++.h>
using namespace std;

#define MAXN 50010

int n, dist[MAXN], nsalas;
vector<int> viz[MAXN];
int pai[MAXN];

int bfs(int start){
	memset(dist, -1, sizeof(dist));

	int ret, l = -1;
	
	queue<int> fila;
	fila.push(start);
	
	dist[start] = 0;
	pai[start] = 0;
	
	while(!fila.empty()){
		int u = fila.front();
		fila.pop();
	
		for(auto x : viz[u]){
			if(dist[x] != -1) continue;
			dist[x] = dist[u] + 1;
			pai[x] = u;
			fila.push(x);

			if(dist[x] > l){
				ret = x;
				l = dist[x];
			}
		}
	}
	
	return ret;
}

int LCA(int a, int b){ //LCA meia boca
	while(a != b){
		a = pai[a];
		b = pai[b];
	}
	return a;
}

int num(int op, int ref){
	int cont = 0, aux,  tempcont, gcont;

	if(op == 1){
		//caso impar (sala no meio)
		for(int i = 1; i <= nsalas/2; i++){
			ref = pai[ref];
		}

		aux = bfs(ref);
		
		vector<int> pontas;
		for(int i = 1; i <= n; i++)
			if(dist[i] == dist[aux]) pontas.push_back(i);
			
		while(!pontas.empty()){
			int u = pontas.front();
			pontas.erase(pontas.begin());
			
			tempcont = 0; gcont = 1;
			
			for(int i = 0; i < pontas.size(); i++){
				if(LCA(u, pontas[i]) == ref){
					tempcont++;
				} else {
					gcont++;
					pontas.erase(pontas.begin()+i);
					i--;
				}
			}
			cont += tempcont * gcont;
		}
	} else {
		//caso par (aresta no meio)
		tempcont = 0;
		for(int i = 1; i <= n; i++){
			if(dist[i] == nsalas-1){
				tempcont++;
			}
		}
		aux = bfs(ref);
		gcont = tempcont;
		tempcont = 0;
		for(int i = 1; i <= n; i++){
			if(dist[i] == nsalas-1){
				tempcont++;
			}
		}
		
		cont += tempcont * gcont;
	}

	return cont;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		viz[x].push_back(y);
		viz[y].push_back(x);
	}
	
	int aux = bfs(1);
	aux = bfs(aux);
	nsalas = dist[aux]+1;

	cout << nsalas << "\n";
	cout << num(nsalas&1, aux) << "\n";

	return 0;
}
