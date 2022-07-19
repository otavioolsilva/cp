#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L[4];
    bool result = false;

    for(int i = 0; i < 4; i++)
        scanf("%d", &L[i]);

    sort(L, L+4);

    for(int i = 0; i < 2; i++)
        if(L[i+2] < L[i] + L[i+1]) result = true;

    printf("%s", result ? "S\n" : "N\n");

    return 0;
}
