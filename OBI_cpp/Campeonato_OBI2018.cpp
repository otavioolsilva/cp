#include <bits/stdc++.h>

using namespace std;

int main()
{
    int pos[17], posLu, posKung;
    for(int cont = 1; cont <= 16; cont++){
        cin >> pos[cont];
        if(pos[cont] == 1) posKung = cont;
        else if(pos[cont] == 9) posLu = cont;
    }

    //oitavas
    if(posKung%2==0 && posKung - posLu == 1) cout << "oitavas" << endl;
    else if(posLu%2==0 && posLu - posKung == 1) cout << "oitavas" << endl;

    //final
    else if(posKung >= 9 && posLu <= 8) cout << "final" << endl;
    else if(posLu >= 9 && posKung <= 8) cout << "final" << endl;

    //quartas + semifinal Kung de referencia
    else if(posKung < posLu){
        if(posKung <= 4){
            if(posLu <= 4) cout << "quartas" << endl;
            else if(posLu <= 8) cout << "semifinal" << endl;
        } else if(posKung <= 8){
            if(posLu <= 8) cout << "quartas" << endl;
        } else if(posKung <= 12){
            if(posLu <= 12) cout << "quartas" << endl;
            else if(posLu <= 16) cout << "semifinal" << endl;
        } else if(posKung <= 16){
            if(posLu <= 16) cout << "quartas" << endl;
        }
    }

    //quartas + semifinal Lu de referencia
    else if(posKung > posLu){
        if(posLu <= 4){
            if(posKung <= 4) cout << "quartas" << endl;
            else if(posKung <= 8) cout << "semifinal" << endl;
        } else if(posLu <= 8){
            if(posKung <= 8) cout << "quartas" << endl;
        } else if(posLu <= 12){
            if(posKung <= 12) cout << "quartas" << endl;
            else if(posKung <= 16) cout << "semifinal" << endl;
        } else if(posLu <= 16){
            if(posKung <= 16) cout << "quartas" << endl;
        }
    }

    return 0;
}
