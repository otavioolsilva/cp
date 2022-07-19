#include <bits/stdc++.h>

using namespace std;

int n, m, yi;
string parede[510];

void dfs(int x, int y){
	int xx;
	int yy;

	xx = x+1;
	yy = y;
	if(xx >= 0 && xx < n && yy >= 0 && yy < m){
		if(parede[xx][yy] == '.'){
			//cout << "embaixo" << endl;
			parede[xx][yy] = 'o';
			dfs(xx, yy);
		}
	}

	xx = x;
	yy = y + 1;
	if(xx >= 0 && xx < n && yy >= 0 && yy < m){
		if(parede[xx][yy] == '.' && parede[x+1][y] == '#'){
			//cout << "lado direito" << endl;
			parede[xx][yy] = 'o';
			dfs(xx, yy);
		}
	}
	
	yy = y - 1;
	if(xx >= 0 && xx < n && yy >= 0 && yy < m){
		if(parede[xx][yy] == '.' && parede[x+1][y] == '#'){
			//cout << "lado esquerdo" << endl;
			parede[xx][yy] = 'o';
			dfs(xx, yy);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){	
		cin >> parede[i];
	}

	for(int i = 0; i < m; i++) {
		if(parede[0][i] == 'o'){
			yi = i;
			break;
		}
	}

	dfs(0, yi);

	for(int i = 0; i < n; i++){
		cout << parede[i] << "\n";
	}

	return 0;
}
