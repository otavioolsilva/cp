// FIBONACCI

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Loop --------------------------------------------------------

ll fib_loop(int n){
	ll ans = 1, aux = 0;

	if(n == 0) return 0;

	while(n > 1){
		ans = ans + aux;
		aux = ans - aux;

		n--;
	}

	return ans;
}


// Recursive ---------------------------------------------------

ll fib_rec(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;

	return fib_rec(n-1) + fib_rec(n-2);
}

// DP ----------------------------------------------------------

ll memo[100];
ll fib_dp(int n){
	if(memo[n] != -1) return memo[n];

	memo[n] = fib_dp(n-1) + fib_dp(n-2);

	return memo[n];
}


// Matrix + fastxp ---------------------------------------------

typedef array<array<ll, 2>, 2> matrix;
matrix operator*(matrix a, matrix b){
	matrix ret;
	ret[0] = {0, 0}; ret[1] = {0, 0};
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return ret;
}

matrix fastxp(matrix base, ll e){
	matrix ret;
	ret[0] = {1, 0}; ret[1] = {0, 1};

	while(e){
		if(e&1) ret = ret*base;

		base = base*base;
		e /= 2; 
	}

	return ret;
}

ll fib_m(int n){
	matrix F, ret;
	F[0] = {1, 1}; F[1] = {1, 0};

	if(n == 0) return 0;

	ret = fastxp(F, n - 1);

	return ret[0][0];
}

//--------------------------------------------------------------

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(memo, -1, sizeof(memo));
	memo[0] = 0;
	memo[1] = 1;

	int n;
	cin >> n;

	cout << fib_(n) << endl;

	return 0;
}
