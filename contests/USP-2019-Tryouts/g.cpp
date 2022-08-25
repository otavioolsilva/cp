#include <bits/stdc++.h>
using namespace std;
#define N 100010

int pai[4*N];
int power[4*N];
int min_acima[4*N];

int main(){
	memset(pai, -1, sizeof(pai));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> power[i];
		min_acima[i] = power[i];
	}
	int disp = n;

	while(m --){
		char ch; cin >> ch;
		if(ch == '?'){
			int i; cin >> i;
			// while(pai[i] != -1) i = pai[i];
			cout << min_acima[i] << endl;
		}
		if(ch == '+'){
			int i, j; cin >> i >> j; // i ganha do j
			min_acima[i] = min(min_acima[i],min_acima[j]); // não dá pra fazer uma árvore esperta mais

			if(pai[i] == -1 && pai[j] == -1){
				pai[i] = disp;
				power[disp] = min(power[i], power[j]);
				disp ++;
			}
			else if(pai[i] == -1){
				pai[i] = pai[j];
				for(int a = i; pai[a] != -1; a = pai[a])
					power[pai[a]] = min(power[pai[a]], power[a]);
			}
			else if(pai[j] == -1){
				pai[j] = pai[i];
				for(int a = j; pai[a] != -1; a = pai[a])
					power[pai[a]] = min(power[pai[a]], power[a]);
			}
			else{
				while(pai[i] != -1) i = pai[i];
				while(pai[j] != -1) j = pai[j];
				pai[i] = disp; pai[j] = disp; power[disp] = min(power[i], power[j]);
				disp ++;
			}
		}
	}
}