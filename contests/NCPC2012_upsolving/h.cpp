#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
const int INF = 0x3f3f3f3f;

int n, h, l, horror[MAXN], dist[MAXN], res = 1009;
vector<int> viz[MAXN];

void bfs(int v){
	queue<int> fila;
	fila.push(v);

	while(!fila.empty()){
		int u = fila.front();
		fila.pop();

		for(int i = 0; i < viz[u].size(); i++){
			int aux = viz[u][i];
			if(dist[aux] == -1){
				dist[aux] = dist[u] + 1;
				fila.push(aux);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dist, -1, sizeof(dist));

	cin >> n >> h >> l;
	for(int i = 0; i < h; i++)
		cin >> horror[i];
	for(int i = 0; i < l; i++){
		int a, b; cin >> a >> b;
		viz[a].push_back(b);
		viz[b].push_back(a);
	}

	for(int i = 0; i < h; i++){
		viz[1009].push_back(horror[i]);
	}

	bfs(1009);

	for(int i = 0; i < n; i++){
		if(dist[i] == -1) dist[i] = INF;
		if(dist[res] < dist[i]) res = i;
	}

	cout << res << "\n";

	return 0;
}
