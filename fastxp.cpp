// FAST EXPO - O(log(n)) 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastxp(ll base, ll e){ // mem: O(log(n))
	if(e == 0) return 1;

	ll ans = fastxp(base, e/2);
	ans = ans * ans;
	if(e&1) ans = ans * base;

	return ans;
}

ll fastxp_it(ll base, ll e){ // mem: O(1)
	ll ans = 1;

	while(e){
		if(e&1) ans *= base;

		base *= base;
		e /= 2; 
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll b, e;
	cin >> b >> e;

	cout << fastxp(b, e) << "\n";
	cout << fastxp_it(b, e) << "\n";

	return 0;
}
