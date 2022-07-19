#include <bits/stdc++.h>
using namespace std;

#define NMAX 510

int idade[NMAX];

int quem[NMAX];

int onde[NMAX];

int marc[NMAX];

vector< int > gerentes[NMAX];

set< int > aux_gerentes[NMAX];

vector< int > grafo[NMAX];

set< int >::iterator it;

void DFS(int pos)
{
    marc[pos] = 1;
    for(int i = 0;i < grafo[pos].size();i++)
    {
        int v = grafo[pos][i];
        if(marc[v] == 0)
        {
            DFS(v);
        }
        for(it = aux_gerentes[v].begin();it != aux_gerentes[v].end();it++)
        {
            aux_gerentes[pos].insert(*it);
        }
        aux_gerentes[pos].insert(v);
    }
}

int main()
{
    int n, m, k, a, b, x, y;

    char op;

    while(scanf("%d %d %d", &n, &m, &k) != EOF)
    {

        for(int i = 1;i <= n;i++)
        {
            aux_gerentes[i].clear();
            gerentes[i].clear();
            grafo[i].clear();
            marc[i] = 0;
            quem[i] = i;
            onde[i] = i;
            scanf("%d", &idade[i]);
        }

        for(int i = 0;i < m;i++)
        {
            scanf("%d %d", &a, &b);
            grafo[b].push_back(a);
        }

        for(int i = 1;i <= n;i++)
        {
            if(marc[i] == 0)
            {
                DFS(i);
            }
        }

        for(int i = 1;i <= n;i++)
        {
            for(it = aux_gerentes[i].begin();it != aux_gerentes[i].end();it++)
            {
                gerentes[i].push_back(*it);
            }
        }

        for(int i = 0;i < k;i++)
        {
            cin >> op;
            scanf("%d", &a);
            if(op == 'T')
            {
                scanf("%d", &b);
                x = onde[a];
                y = onde[b];
                swap(quem[x], quem[y]);
                swap(onde[a], onde[b]);
            }else
            {
                a = onde[a];
                if(gerentes[a].size() == 0)
                {
                    printf("*\n");
                }else
                {
                    int menor = 1000000;
                    for(int i = 0;i < gerentes[a].size();i++)
                    {
                        int val = quem[gerentes[a][i]];
                        menor = min(menor, idade[val]);
                    }
                    printf("%d\n", menor);
                }
            }
        }
    }


    return 0;
}
