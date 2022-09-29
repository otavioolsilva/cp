#include <bits/stdc++.h>
using namespace std;

string n;
int m, cont;
queue<string> fila;
map<char, int> dic;

bool check(string u){
	for(int i = 0; i < u.length(); i++){
		if(dic[u[i]] != n[i] - 48) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < m; i++){
		string in; cin >> in;
		if(in.length() == n.length()){
			fila.push(in);
		}
	}

	cont = 2;
	for(int i = 0; i < 26; i++){
		if(i == 3 || i == 6 || i == 9 || i == 12 || i == 15 || i == 19 || i == 22) cont++;
		dic[97+i] = cont;
	}

	cont = 0;

	while(!fila.empty()){
		if(check(fila.front())) cont++;
		fila.pop();
	}

	cout << cont << "\n";

	return 0;
}
