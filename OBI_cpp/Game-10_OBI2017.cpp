#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, D, A;
    cin >> N >> D >> A;

    if(A < D){
        cout << D - A << endl;
    } else if(A > D){
        cout << (N-A)+D << endl;
    } else cout << "0" << endl;

    return 0;
}
