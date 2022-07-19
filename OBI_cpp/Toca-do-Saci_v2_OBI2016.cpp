#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+10;
int N, M, inicio_i, inicio_j, obj_i, obj_j;
int mapa[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int r, int c){
	if(r == obj_i && obj_j == c){
		cout << dist[obj_i][obj_j] << "\n";
		exit(0);
	}
	if(mapa[r][c] == 0) return;
	vis[r][c] = 1;

	for(int k = 0; k < 4; k++){
		int rr = r + dx[k];
		int cc = c + dy[k];
		if(rr < 0 || rr >= N || cc < 0 || cc >= M){
			continue;
		}
		if(!vis[rr][cc]){
			dist[rr][cc] = dist[r][c] + 1;
			dfs(rr, cc);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> mapa[i][j];
			if(mapa[i][j] == 2){
				inicio_i = i;
				inicio_j = j;
			} else if(mapa[i][j] == 3) {
				obj_i = i;
				obj_j = j;
			}
		}
	}
	
	dist[inicio_i][inicio_j] = 1;

	dfs(inicio_i, inicio_j);
	
	//cout << dist[obj_i][obj_j] << "\n";

	return 0;
}
