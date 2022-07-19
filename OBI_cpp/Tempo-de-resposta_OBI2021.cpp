#include <bits/stdc++.h>

using namespace std;

int reg[110], amg[110]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char ant;

	while(n > 0){
		char op;
		int id;
		cin >> op >> id;

		if(op != 'T'){
			for(int i = 1; i < 101; i++){
				if(amg[i]%2 != 0 && ant != 'T') reg[i]++;
			}
			amg[id]++;
		} else {
			for(int i = 1; i < 101; i++){
				if(amg[i]%2 != 0) reg[i] += id;
			}
		}

		ant = op;

		n--;
	}

	for(int i = 1; i < 101; i++){
		if(amg[i] == 0) continue;
		else if(amg[i] % 2 == 0) cout << i << " " << reg[i] << endl;
		else cout << i << " " << -1 << endl;
	}

	return 0;
}
