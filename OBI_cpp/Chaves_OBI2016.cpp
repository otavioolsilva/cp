#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, cI = 0, cF = 0, cont = 0;
    string frase;
    cin >> N;

    while(N >= 0){
        getline(cin, frase);
        for(int i=0; i < frase.length();i++){
            string aux;
            aux = frase.at(i);
            if(aux == "{") cI++;
            else if(aux == "}") cF++;
            if(cF > cI) cont++;
        }
        N--;
    }

    if(cI != cF) cont++;

    if(cont > 0) cout << "N" << endl;
    else cout << "S" << endl;

    return 0;
}
