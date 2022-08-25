// Site da OBI desistiu de receber submissão,
// código só foi testado com o exemplo do enunciado :(

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
const double INF = 0x3f3f3f3f;

int n;
double d, memo[MAXN][MAXN];
vector<pair<double, double>> baterias;

double pd(int i, int dist){
	double aux = pow(baterias[dist].first - baterias[i].first, 2)/baterias[i].second;

	if(dist == n) return aux;

	double& pdm = memo[i][dist];
	if(pdm != -1) return pdm;

	return pdm = min(aux + pd(dist, dist+1), pd(i, dist+1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < MAXN; i++){
		for(int j = 0; j < MAXN; j++)
			memo[i][j] = -1.0;
	}

	cin >> n >> d;
	for(int i = 0; i < n; i++){
		double p, c; cin >> p >> c;
		baterias.push_back({p, c});
	}

	baterias.push_back({d, 0});

	sort(baterias.begin(), baterias.end());

	cout << fixed << setprecision(3) << pd(0, 1) << "\n";

	return 0;
}
