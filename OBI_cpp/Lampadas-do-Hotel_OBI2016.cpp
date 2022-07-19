#include <bits/stdc++.h>
using namespace std;

int main()
{
    int iA, iB, fA, fB;
    cin >> iA >> iB >> fA >> fB;

    if(iA != fA){
        cout << "1" << endl;
    } else if(iB != fB) cout << "2" << endl;
    else cout << "0" << endl;

    return 0;
}
