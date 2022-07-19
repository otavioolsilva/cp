#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	n -= 3;

	if(n%8 == 3) cout << "1\n";
	else if(n%8 == 4) cout << "2\n";
	else cout << "3\n";

	return 0;
}
