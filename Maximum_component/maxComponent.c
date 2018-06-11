#include <stdio.h>

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int nnode, medge, a, b, max = 0, i;
        scanf("%d%d", &nnode, &medge);
        int weight[nnode], group[nnode];
        for(i = 0; i < nnode; i++)
        {
            scanf("%d", &weight[i]);
            group[i] = -1;
        }
        if(medge == 0)
        {
            for(i = 0; i < nnode; i++)
            {
                if(weight[i] > max)
                    max = weight;
            }
        }
        else
        {
            for(i = 0; i < medge; i++)
            {
                scanf("%d%d", &a, &b);
                while(group[a] >= 0)
                {
                    a = group[a];
                }
                while(group[b] >= 0)
                {
                    b = group[b];
                }
                if(a != b)
                {
                    if(a > b)
                    {
                        weight[a] += weight[b];
                        if(weight[a] > max)
                            max = weight[a];
                        group[a] += group [b];
                        group[b] = a;
                    }
                    else
                    {
                        weight[b] += weight[a];
                        if(weight[b] > max)
                            max = weight[b];
                        group[b] += group[a];
                        group[a] = b;
                    }
                }
            }
        }
        printf("%d", max);
        if(tcase)
            printf("\n");
    }
    return 0;
}
