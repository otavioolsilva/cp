#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll s = 0;
vector<pair<ll, ll>> rounds;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(ll i = 0; i < n; i++){
		ll a, b; cin >> a >> b;
		rounds.push_back({b, a});
		s += a;
	}

	sort(rounds.begin(), rounds.end());

	ll m = s - rounds[n-1].first;
	ll acc = 0;
	for(ll i = n-2; i >= 0 ; i--){
		acc += rounds[i+1].second;
		if(m < (s - acc)-rounds[i].first) m = (s - acc)-rounds[i].first;
	}

	cout << m << "\n";
}