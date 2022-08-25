#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> livros, slivros;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; i++){
		ll aux; cin >> aux;
		livros.push_back(aux);
	}

	sort(livros.begin(), livros.end());

	slivros.push_back(0);
	for(int i = 0; i < n; i++)
		slivros.push_back(slivros[i]+livros[i]);

	/*for(int i = 0; i < slivros.size(); i++)
		cout << slivros[i] << " ";
	cout << endl;*/

	int m;
	for(m = 0; m < n; m ++)
		if(slivros[m] < livros[m] - 1){
			cout << slivros[m] + 1 << endl;
			break;
		}

	if(m == n)
		cout << slivros[n] + 1 << endl;



	
}