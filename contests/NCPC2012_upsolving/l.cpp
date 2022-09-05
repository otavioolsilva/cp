#include <bits/stdc++.h>
using namespace std;
#define MAXN 1123

long double x[MAXN];

vector<pair<long double, bool>> line_sweep;
vector<long double> intervalos;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	long double l; cin >> l;

	for(int i = 0; i < n; i++){
		cin >> x[i];
	}

	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			long double delta;
			delta = abs(x[i] - x[j]);
			if(delta <= 10){
				line_sweep.push_back({delta, 0});
				line_sweep.push_back({10, 1});
			}
			for(int cont = 1; delta/(cont * l - 1) >= 0.1; cont++){
				if(delta/(cont * l + 1) > 10) continue;
				line_sweep.push_back({delta/(cont * l + 1), 0});
				line_sweep.push_back({delta/(cont * l - 1), 1});
			}
		}
	}
	line_sweep.push_back({10, 0});
	line_sweep.push_back({10, 1});
	sort(line_sweep.begin(), line_sweep.end());

	int cont = 0;
	for(auto [valor, tipo] : line_sweep){
		if((cont == 0 && tipo == 0) || (cont == 1 && tipo == 1)) intervalos.push_back(valor);
		if (tipo == 0) cont++;
		else cont--;
	}

	sort(intervalos.begin(), intervalos.end(), greater<>());


	if(intervalos.size() == 2 && intervalos[1] <= 0.1 && intervalos[0] >= 10){
		cout << "no fika" << endl;
		return 0;
	}

	cout << fixed << setprecision(9) << intervalos[1] << endl;
	return 0;
}