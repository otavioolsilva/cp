#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

typedef array<array<ll, 3>, 3> matrix;
matrix operator*(matrix a, matrix b){
	matrix ret;
	ret[0] = {0, 0, 0}; ret[1] = {0, 0, 0}; ret[2] = {0, 0, 0};

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				ret[i][j] = (a[i][k]*b[k][j] + ret[i][j])%mod;
			}
		}
	}

	return ret;
}

ll fastxp(int e){
	e -= 2;

	matrix base, ans;
	base[0] = {1, 4, 2}; base[1] = {1, 0, 0}; base[2] = {0, 1, 0};
	ans[0] = {1, 0, 0}; ans[1] = {0, 1, 0}; ans[2] = {0, 0, 1};

	while(e){
		if(e&1) ans = ans * base;

		base = base*base;
		e /= 2;
	}

	return (ans[0][0]*5 + ans[0][1] + ans[0][2])%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if(n == 0 || n == 1) cout << "1\n";
	else if(n == 2) cout << "5\n";
	else cout << fastxp(n) << "\n";

	return 0;
}
