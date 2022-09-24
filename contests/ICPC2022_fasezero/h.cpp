#include <bits/stdc++.h>
using namespace std;

long long c;

long long bs(){
	long long floor, top, mid, best;
	floor = 1; top = 830000000; best = 1;
	while(floor <= top){
		mid = (floor+top)/2;

		long long aux = 0;
		aux = 2*mid+3*((mid*(mid-1))/2);

		if(aux == c) return mid;
		if(aux > c){
			top = mid-1;
		} else {
			best = mid;
			floor = mid+1;
		}

	}
	return best;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--){
		cin >> c;
		cout << bs() << "\n";
	}

	return 0;
}
