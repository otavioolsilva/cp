#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x, w = 0, m = 0, res = 0; cin >> x;
	string line; cin >> line;
	
	for(int i = 0; i < line.length(); i++){
		if(line[i] == 'W') w++;
		else m++;

		if(abs(w-m) >= 2+x){
			res = i-1;
			break;
		} else if(i == line.length()-1 && abs(w-m) >= 1+x) {
			res = i;
			break;
		}

		res++;
	}
	
	cout << res << "\n";

	return 0;
}
