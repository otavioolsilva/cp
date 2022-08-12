#include <bits/stdc++.h>
using namespace std;

int n, f;
int mapa[510][510], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void bfs(){
	queue<pair<int, int>> fila;
	if(mapa[0][0] <= f){
		mapa[0][0] = -1;
		fila.push({0,0});
	}

	while(!fila.empty()){
		pair<int, int> u = fila.front();
		fila.pop();

		for(int i = 0; i < 4; i++){
			int xx = u.first + dx[i];
			int yy = u.second + dy[i];
			if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;

			if(mapa[xx][yy] <= f && mapa[xx][yy] != -1){
				mapa[xx][yy] = -1;
				fila.push({xx, yy});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> f;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		for(int j = 0; j < a.size(); j++){
			mapa[i][j] = a[j]-'0';
		}
	}

	bfs();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mapa[i][j] == -1) cout << "*";
			else cout << mapa[i][j];
		}
		cout << "\n";
	}

	return 0;
}
