#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define ll unsigned long long

bool eh_primo[N];
vector<ll> primos;

void crivo(){
	for(ll i = 0; i < N; i ++){
		eh_primo[i] = 1;
	}
	for(ll i = 2; i < N; i ++){
		if(eh_primo[i]){
			primos.push_back(i);
			for(ll j = 2; j*i < N; j ++)
				eh_primo[j*i] = 0;
		}
	}
}

ll mdc(ll x, ll y){
	if(x == 0) return y;
	return mdc(y%x,x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	crivo();
	ll A, B; cin >> A >> B; B /= mdc(A,B);

	ll ans = 1;

	for(ll i = 0; i < primos.size(); i ++){
		ll p = primos[i];
		/* cout << p << " " << B << endl; */
		if(B % p == 0){
			ans *= p;
			while(B % p == 0){
				B /= p;
			}
		}
	}


	if(B > 1){
		ll raiz = sqrtl(B);
		if(raiz * raiz == B)
			ans*= raiz;
			
		else
			ans *= B;
	}

	if(ans == 1) ans = 2;
	cout << ans << endl;
}