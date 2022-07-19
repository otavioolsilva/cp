#include <bits/stdc++.h>

using namespace std;

vector<int> seq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, sum = 0;
	cin >> n;

	while(n > 0){
		int num;
		cin >> num;

		if(num != 0) seq.push_back(num);
		else seq.pop_back();

		n--;
	}

	for(int i = 0; i < seq.size(); i++){
		sum += seq[i];
	}

	cout << sum << endl;	

	return 0;
}
