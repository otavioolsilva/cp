#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	string a, b;
	cin >> a >> b;
	if(a.length() >= b.length()) cout << "go\n";
	else cout << "no\n";
 
	return 0;
}