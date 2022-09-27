#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 10010

int v, n, m; // v = orçamento // n = vértices // m = arestas
vector<array<int, 3>> viz[MAXN];
int dist[MAXN][210];

void dijkstra(int start){
	set<array<int, 3>> q;
	q.insert({0, 0, start});

	while(!q.empty()){
		array<int, 3> aux = *q.begin();
		q.erase(q.begin());

		int u = aux[2], t = aux[0], p = aux[1]; // u = vértice atual // t = tempo // p = preço

		if(dist[u][p] < INF) continue;
		dist[u][p] = t;

		for(auto x : viz[u]){
			if(p + x[2] > v || dist[x[0]][p + x[2]] < INF) continue;
			q.insert({t + x[1], p + x[2], x[0]});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dist, INF, sizeof(dist));

	cin >> v >> n >> m;
	for(int i = 0; i < m ; i++){
		int a, b, t, p; cin >> a >> b >> t >> p;
		viz[a].push_back({b, t, p});
		viz[b].push_back({a, t, p});
	}

	int x, y, res = INF;
	cin >> x >> y;

	dijkstra(x);

	for(int i = 0; i <= v; i++) res = min(res, dist[y][i]);
	if(res >= INF) res = -1;

	cout << res << "\n";

	return 0;
}
