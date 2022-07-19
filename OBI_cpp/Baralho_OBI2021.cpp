#include <bits/stdc++.h>

using namespace std;

int C[14], E[14], U[14], P[14];

void check(int V[14]){
	bool flag = 0;
	int cont = 0;
	for(int i = 1; i < 14 && !flag; i++){
		if(V[i] == 0) cont++;
		else if(V[i] > 1) flag = 1;
	}

	if(flag) cout << "erro" << "\n";
	else cout << cont << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string in;
	getline(cin, in);

	for(int i = 0; i < in.length(); i += 3){
		int a;
		char c;

		c = in[i];
		a = (c - '0') * 10;
		
		c = in[i+1];
		a += (c - '0');

		c = in[i+2];

		if(c == 'C') C[a]++;
		else if(c == 'E') E[a]++;
		else if(c == 'U') U[a]++;
		else if(c == 'P') P[a]++;
	}

	check(C);
	check(E);
	check(U);
	check(P);

	return 0;
}
