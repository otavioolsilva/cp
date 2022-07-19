#include <bits/stdc++.h>

using namespace std;

int main(){

    int L, C;
    cin >> L >> C;

    //TIPO 1 DE LAJOTA
    cout << ((L-1)*(C-1)) + (C*L) << endl;
    //TIPO 2 DE LAJOTA
    cout << ((C - 1) + (L - 1)) * 2 << endl;

    return 0;
}
