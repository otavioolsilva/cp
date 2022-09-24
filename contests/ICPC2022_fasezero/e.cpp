#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, d, consumo;
	double res;
	cin >> n >> l >> d;

	consumo = n*d;
	res = (double)consumo/(l*1000);

	cout << ceil(res)*l << "\n"; 

	return 0;
}
