#include <bits/stdc++.h>

using namespace std;

int main(){

    int A, N, cont = 0;
    cin >> A >> N;
    int F[N];

    while(N != 0){
        cin >> F[N];
        if(F[N]*A >= 40000000) cont++;
        N--;
    }

    cout << cont << endl;

    return 0;
}
