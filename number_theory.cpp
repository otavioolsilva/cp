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

// N ESCOLHE K mod MOD
ll fat[MAXN], fat_inv[MAXN];

ll inv(ll i){
  return (i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD);
}

void precalc(){
  fat[0] = 1;
  fat_inv[0] = 1;
  
  for(int i = 1; i < MAXN; i++){
    fat[i] = (fat[i-1] * i) % MOD;
    fat_inv[i] = inv(fat[i]) % MOD;
  }
}

ll comb(ll n, ll k){
	if(k > n || k < 0) return 0;
	return (((fat[n] * fat_inv[n-k]) % MOD) * fat_inv[k]) % MOD;
}

