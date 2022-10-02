#include <bits/stdc++.h>
using namespace std;

#define MAXNM 100010

int n, m, dist[MAXNM], pai[MAXNM];
vector<int> circ[MAXNM];
vector<int> quad[MAXNM];
pair<int, int> refcirc[2], refquad[2];

pair<int, int> bfs(int start, bool op){
	memset(dist, -1, sizeof(dist));

	pair<int, int> ret = {-1, -1};
	queue<int> fila;

	dist[start] = 0;
	pai[start] = 0;
	fila.push(start);

	while(!fila.empty()){
		int u = fila.front();
		fila.pop();

		if(op){
			for(auto x : circ[u]){
				if(dist[x] != -1) continue;
				dist[x] = dist[u] + 1;
				pai[x] = u;
				fila.push(x);

				if(dist[x] > ret.second){
					ret.first = x;
					ret.second = dist[x];
				}
			}
		} else {
			for(auto x : quad[u]){
				if(dist[x] != -1) continue;
				dist[x] = dist[u] + 1;
				pai[x] = u;
				fila.push(x);

				if(dist[x] > ret.second){
					ret.first = x;
					ret.second = dist[x];
				}
			}
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		circ[a].push_back(b);
		circ[b].push_back(a);
	}
	for(int i = 1; i < m; i++){
		int a, b; cin >> a >> b;
		quad[a].push_back(b);
		quad[b].push_back(a);
	}

	int  rcirc, rquad;

	// ESTAÇÃO CÍRCULO
	refcirc[0] = bfs(1, 1);
	refcirc[1] = bfs(refcirc[0].first, 1);

	if(refcirc[1].second&1){
		int aux = 0;
		
		aux = refcirc[1].first;
		for(int i = 0; i < refcirc[1].second/2; i++){
			aux = pai[aux];
		}
		rcirc = pai[aux];

		refcirc[0] = bfs(1, 1);
		if(dist[aux] > dist[rcirc]) rcirc = aux;
	} else {
		rcirc = refcirc[1].first;
		for(int i = 0; i < refcirc[1].second/2; i++){
			rcirc = pai[rcirc];
		}
	}

	// ESTAÇÃO QUADRADO
	refquad[0] = bfs(1, 0);
	refquad[1] = bfs(refquad[0].first, 0);

	if(refquad[1].second&1){
		int aux = 0;
		
		aux = refquad[1].first;
		for(int i = 0; i < refquad[1].second/2; i++){
			aux = pai[aux];
		}
		rquad = pai[aux];
		
		refquad[0] = bfs(1, 0);
		if(dist[aux] > dist[rquad]) rquad = aux;
	} else {
		rquad = refquad[1].first;
		for(int i = 0; i < refquad[1].second/2; i++){
			rquad = pai[rquad];
		}
	}

	cout << rcirc << " " << rquad << "\n";

	return 0;
}
