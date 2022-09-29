#include <bits/stdc++.h>
using namespace std;

#define MAXN 50010

int n, dist[MAXN], nsalas;
vector<int> viz[MAXN];
int pai[MAXN];
bool vis[MAXN];

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

int dfs(int v, int ref){
	if(vis[v]) return 0;
	vis[v] = 1;
	if(dist[v] == nsalas/2) return 1;

	int ret = 0;
	for(auto x : viz[v]){
		if(x != ref) ret += dfs(x, ref);
	}

	return ret;
}

int num(int op, int ref){
	int cont = 0, aux,  tempcont, gcont;

	if(op == 1){
		//caso impar (sala no meio)
		for(int i = 1; i <= nsalas/2; i++){
			ref = pai[ref];
		}

		aux = bfs(ref);
		
		queue<int> fila;
		for(int i = 1; i <= n; i++)
			if(dist[i] == 1) fila.push(i);
		
		vector<int> res;
		while(!fila.empty()){
			res.push_back(dfs(fila.front(), ref));
			fila.pop();
		}

		cont = 0; tempcont = 0;
		for(int i = 0; i < res.size(); i++){
			cont += res[i];
			tempcont += res[i]*res[i];
		}
		cont *= cont;
		cont -= tempcont;
		cont /= 2;
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
