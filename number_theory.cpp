// Some number theory algorithms

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX_CRIVO 100005

// CRIVO DE ERASTÓTENES
vector<int> prim;
int mark[MAX_CRIVO];	
void crivo(){
	for(int i = 2; i < MAX_CRIVO; i++){
		if(!mark[i]) prim.push_back(i);
		for(int p: prim){
			if(i*p >= MAX_CRIVO) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

// FUNÇÃO TOTIENTE
ll tot(ll x){
	ll ans = x;
	for(auto z: prim){
		if(z*z > x) break;
		if(x%z == 0){
			while(x%z == 0){
				x /= z;
			}
			ans -= ans/z;
		}
	}
	if(x != 1) ans -= ans/x;
	return ans;
}

// MDC
ll mdc(ll a, ll b){
	return (b == 0) ? a : mdc(b, a%b);
}
