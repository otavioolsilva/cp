#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
typedef long long ll;
const int mod = 1e9 + 7;

int n;
ll memo[MAXN];

ll dp(int i){
	if(i == 0 || i == 1) return 1;
	if(i == 2) return 5;

	ll& dpm = memo[i];
	if(dpm != -1) return memo[i];

	return dpm = (dp(i-1) + 4*dp(i-2) + 2*dp(i-3))%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(memo, -1, sizeof(memo));

	cin >> n;
	cout << dp(n) << "\n";

	return 0;
}
