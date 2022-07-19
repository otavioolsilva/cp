#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cont = 0;
	char c;
	for(int i = 0; i < 6; i++) {
		cin >> c;
		if(c == 'V') cont++;
	}

	if(cont > 4) cout << "1\n";
	else if(cont > 2) cout << "2\n";
	else if(cont > 0) cout << "3\n";
	else cout << "-1\n";

	return 0;
}
