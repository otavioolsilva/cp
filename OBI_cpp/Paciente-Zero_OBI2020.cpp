#include <bits/stdc++.h>

using namespace std;

vector<int> seq;
set<int> infectados;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;

	while(c > 0){
		int P, I, aux;
		cin >> P >> I;

		for(int j = 0; j < I; j++){
			cin >> aux;
			infectados.insert(aux);
		}

		seq.push_back(P);

		c--;
	}

	sort(seq.begin(), seq.end());

	for(int i = 0; i < seq.size(); i++){
		if(infectados.find(seq[i]) == infectados.end()) cout << seq[i] << "\n";
	}

	return 0;
}
