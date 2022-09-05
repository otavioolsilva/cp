#include <bits/stdc++.h>
using namespace std;

const int EPS = 1e-8;

int sign(int x) { return (x > EPS) - (x < -EPS); }

struct point{
	int x, y;

	point operator-(point p){ return {x - p.x, y - p.y}; }
	int operator^(point p){ return x * p.y - y * p.x; } //determinante matriz produto vetorial
};

struct line{
	point p1, p2;

	bool parallel(line aux){ return (p2.y - p1.y)*(aux.p2.x - aux.p1.x) == (p2.x - p1.x)*(aux.p2.y - aux.p1.y); }
	//comparação pelos coeficientes angulares
	
	bool equal(line aux){ return parallel(aux) && sign((aux.p1-p1)^(p2-p1)) == 0 && sign((aux.p2-p1)^(p2-p1)) == 0; }
	//se são iguais, vão ser paralelas e apresentar pontos em comum (produto vetorial entre três pontos == 0)
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int w, n, act; cin >> w >> n; //w = espaços //n = linhas iniciais
	bool allParallel = true;
	vector<line> l;

	for(int i = 0; i < n; i++){ //leitura
		line cur; bool isNew = true;
		cin >> cur.p1.x >> cur.p1.y >> cur.p2.x >> cur.p2.y;
		for(int i = 0; i < l.size() && isNew; i++){
			if(cur.equal(l[i])) isNew = false;
		}
		if(isNew) l.push_back(cur);
	}

	for(int i = 1; i < l.size() && allParallel; i++) //corner case todas paralelas
		if(!l[0].parallel(l[i])) allParallel = false;

	if(allParallel) act = l.size()+1;
	else act = l.size()*2;
 
	if(w <= act) cout << "0\n";
	else cout << max(1, (int)((w+1)/2 - l.size())) << "\n";

	return 0;
}
