#include <bits/stdc++.h>

using namespace std;

vector<int> vencedores;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, u;
	cin >> n >> k >> u;

	unordered_set<int> cartelas[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			int aux;
			cin >> aux;
			cartelas[i].insert(aux);
		}
	}

	bool flag = 0;

	for(int i = 0; i < u; i++){
		int aux;
		cin >> aux;

		for(int j = 0; j < n && !flag; j++){
			if(cartelas[j].find(aux) != cartelas[j].end()){	
				cartelas[j].erase(aux);
				if(cartelas[j].empty()) vencedores.push_back(j);
			}
		}

		if(!vencedores.empty()) flag = 1;
	}

	sort(vencedores.begin(), vencedores.end());

	cout << vencedores[0]+1;
	for(int i = 1; i < vencedores.size(); i++){
		cout << " " << vencedores[i]+1;
	}
	cout << "\n";

	return 0;
}
