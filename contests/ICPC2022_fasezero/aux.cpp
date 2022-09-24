#include <bits/stdc++.h>
using namespace std;

int main(){
	long long base = 1;
	cout << "{1, ";
	for(int i = 1; i < 60; i++){
		base = base*2;
		cout << base << ", ";
	}
	cout << base*2 << "}\n";

	return 0;
}