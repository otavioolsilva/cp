#include <bits/stdc++.h>

using namespace std;

int mapa[510][510], n, f;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y){
	for(int z = 0; z < 4; z++){
		int xx = x + dx[z];
		int yy = y + dy[z];
		if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;

		if(mapa[xx][yy] != -1 && mapa[xx][yy] <= f){
			mapa[xx][yy] = -1;
			dfs(xx, yy);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> f;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			mapa[i][j] = c - '0';
		}
	}

	if(mapa[0][0] <= f){
		mapa[0][0] = -1;
		dfs(0, 0);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mapa[i][j] == -1) cout << "*";
			else cout << mapa[i][j];
		}
		cout << "\n";
	}


	return 0;
}
