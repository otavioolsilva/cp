#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 10010

int n, k, c, etiq[MAXN]; // n = quadrados // k = etiquetas // c = tamanho etiqueta
int memo[MAXN][MAXN];

int dp(int i, int cont){
	if(i == n && cont == 0) return 0;
	if(cont < 0 || i >= n || cont*c > n-i) return -INF;

	int &dpm = memo[i][cont];
	if(dpm != -1) return dpm;
	dpm = 0;

	return dpm = max(dp(i+c, cont-1), dp(i+1, cont)+etiq[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(memo, -1, sizeof(memo));

	cin >> n >> k >> c;
	for(int i = 0; i < n; i++)
		cin >> etiq[i];

	cout << dp(0, k) << "\n";

	return 0;
}
